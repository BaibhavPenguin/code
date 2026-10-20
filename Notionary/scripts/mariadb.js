/**
 * Limitless Archive - lite4mariadb WASM Runner Module
 */
let mariadbModule = null;
let mariadbDbHandle = 0;
window.__isMySQLLoading = false;
window.__isMySQLReady = false;

window.updateMySQLBadges = function(status) {
  document.querySelectorAll('.mysql-status-badge').forEach(function(badge) {
    if (status === 'ready') {
      badge.className = 'mysql-status-badge ready';
      badge.querySelector('.mysql-status-text').textContent = 'MySQL Ready';
    } else if (status === 'loading') {
      badge.className = 'mysql-status-badge';
      badge.querySelector('.mysql-status-text').textContent = 'Initializing...';
    } else {
      badge.className = 'mysql-status-badge';
      badge.querySelector('.mysql-status-text').textContent = 'Waiting...';
    }
  });
};

window.ensureMySQL = async function() {
  if (window.__isMySQLReady && mariadbModule) return mariadbModule;
  if (window.__isMySQLLoading) {
    while (!window.__isMySQLReady) {
      await new Promise(r => setTimeout(r, 100));
    }
    return mariadbModule;
  }

  window.__isMySQLLoading = true;
  window.updateMySQLBadges('loading');

  try {
    const basePath = new URL('../vendor/lite4mariadb/', window.location.href).href;
    const mod = await import(basePath + 'lite4mariadb.js');

    const Factory = 
      mod.Lite4MariaDB || 
      mod.MariaDB || 
      mod.createMariaDB || 
      (typeof mod.default === 'function' ? mod.default : mod.default?.Lite4MariaDB || mod.default?.MariaDB);

    const options = {
      locateFile: (file) => basePath + file,
      mainScriptUrlOrBlob: basePath + 'lite4mariadb.worker.js'
    };

    let inst = null;
    if (typeof Factory === 'function') {
      try {
        inst = await Factory(options);
      } catch (e) {
        inst = new Factory(options);
      }
    } else if (typeof mod.create === 'function') {
      inst = await mod.create(options);
    } else if (typeof mod.default === 'object' && mod.default !== null) {
      inst = mod.default;
    } else {
      inst = mod;
    }

    mariadbModule = inst;

    if (typeof mariadbModule._l4m_open === 'function') {
      try {
        mariadbDbHandle = mariadbModule._l4m_open();
      } catch (e) {
        mariadbDbHandle = 1;
      }
    }

    try {
      await executeSingleQuery(mariadbModule, "CREATE DATABASE IF NOT EXISTS sandbox; USE sandbox;");
    } catch (_) {}

    window.__isMySQLReady = true;
    window.__isMySQLLoading = false;
    window.updateMySQLBadges('ready');
    return mariadbModule;
  } catch (err) {
    window.__isMySQLLoading = false;
    window.updateMySQLBadges('waiting');
    console.error('Failed to load local lite4mariadb module:', err);
    throw err;
  }
};

async function executeSingleQuery(module, sql) {
  if (typeof module.query === 'function') return await module.query(sql);
  if (typeof module.execute === 'function') return await module.execute(sql);
  if (typeof module.exec === 'function') return await module.exec(sql);

  const queryFn = module._l4m_query || module._l4m_exec_multi;
  if (typeof queryFn !== 'function') {
    throw new Error('No execution method on WASM module.');
  }

  let sqlPtr = 0;
  if (typeof module.stringToUTF8 === 'function' && typeof module._malloc === 'function') {
    const length = (module.lengthBytesUTF8 ? module.lengthBytesUTF8(sql) : sql.length * 4) + 1;
    sqlPtr = module._malloc(length);
    module.stringToUTF8(sql, sqlPtr, length);
  } else if (typeof module.allocateUTF8 === 'function') {
    sqlPtr = module.allocateUTF8(sql);
  } else if (typeof module.ccall === 'function') {
    return module.ccall('l4m_query', 'string', ['string'], [sql]);
  }

  if (!sqlPtr) {
    throw new Error('Failed to allocate SQL query in memory.');
  }

  let resPtr = 0;
  try {
    if (queryFn.length >= 2) {
      resPtr = await queryFn(mariadbDbHandle, sqlPtr);
    } else {
      resPtr = await queryFn(sqlPtr);
    }
  } finally {
    if (typeof module._free === 'function') {
      module._free(sqlPtr);
    }
  }

  if (!resPtr) {
    return null;
  }

  let rawResult = '';
  if (typeof module.UTF8ToString === 'function') {
    rawResult = module.UTF8ToString(resPtr);
  }

  if (typeof module._l4m_free === 'function') {
    module._l4m_free(resPtr);
  } else if (typeof module._free === 'function') {
    module._free(resPtr);
  }

  if (rawResult && typeof rawResult === 'string') {
    const trimmed = rawResult.trim();
    if ((trimmed.startsWith('{') && trimmed.endsWith('}')) || (trimmed.startsWith('[') && trimmed.endsWith(']'))) {
      try {
        return JSON.parse(trimmed);
      } catch (e) {
        return rawResult;
      }
    }
  }

  return rawResult;
}

function formatSQLResults(res, query) {
  const q = (query || '').trim().toUpperCase();
  const isMutation = /^(CREATE|DROP|ALTER|INSERT|UPDATE|DELETE|USE|SET|RENAME|TRUNCATE)\b/.test(q);

  if (typeof res === 'object' && res !== null && (res.error || res.errorMessage || res.errno)) {
    const code = res.errno ? ` (${res.errno})` : '';
    const msg = res.error || res.errorMessage || 'Execution failed';
    return `ERROR${code}: ${msg}`;
  }

  if (typeof res === 'string') {
    const trimmed = res.trim();
    if (/^(ERROR|\bERR\b|FATAL)/i.test(trimmed)) {
      return trimmed;
    }
    if (trimmed.startsWith('+') || trimmed.includes('|')) {
      return trimmed;
    }
    if (trimmed.length === 0) {
      return isMutation ? 'Query OK, 0 rows affected (0.01 sec)' : 'Empty set (0.00 sec)';
    }
    return trimmed;
  }

  if (res === null || res === undefined) {
    return isMutation ? 'Query OK, 0 rows affected (0.01 sec)' : 'Empty set (0.00 sec)';
  }

  let rows = null;
  let cols = null;

  if (Array.isArray(res)) {
    rows = res;
  } else if (typeof res === 'object') {
    if (Array.isArray(res.rows)) {
      rows = res.rows;
      cols = res.columns || res.fields;
    } else if (Array.isArray(res.values)) {
      rows = res.values;
      cols = res.columns;
    } else if (res.affectedRows !== undefined || res.changes !== undefined) {
      const count = res.affectedRows ?? res.changes;
      return `Query OK, ${count} row${count === 1 ? '' : 's'} affected (0.01 sec)`;
    }
  }

  if (!rows || rows.length === 0) {
    return isMutation ? 'Query OK, 0 rows affected (0.01 sec)' : 'Empty set (0.00 sec)';
  }

  if (Array.isArray(rows[0])) {
    if (!cols || !Array.isArray(cols)) {
      cols = rows[0].map((_, i) => `Col ${i + 1}`);
    } else {
      cols = cols.map(c => (typeof c === 'object' && c !== null ? c.name || c.columnName || String(c) : String(c)));
    }

    const colWidths = cols.map((col, idx) => 
      Math.max(String(col).length, ...rows.map(r => String(r[idx] ?? 'NULL').length))
    );

    const separator = '+' + colWidths.map(w => '-'.repeat(w + 2)).join('+') + '+';
    const header = '| ' + cols.map((col, i) => String(col).padEnd(colWidths[i])).join(' | ') + ' |';
    const body = rows.map(r => 
      '| ' + r.map((val, i) => String(val ?? 'NULL').padEnd(colWidths[i])).join(' | ') + ' |'
    ).join('\n');

    return `${separator}\n${header}\n${separator}\n${body}\n${separator}\n${rows.length} row${rows.length > 1 ? 's' : ''} in set`;
  }

  if (typeof rows[0] === 'object' && rows[0] !== null) {
    const keys = Object.keys(rows[0]);
    const colWidths = {};
    keys.forEach(k => {
      colWidths[k] = Math.max(k.length, ...rows.map(row => String(row[k] ?? 'NULL').length));
    });

    const separator = '+' + keys.map(k => '-'.repeat(colWidths[k] + 2)).join('+') + '+';
    const header = '| ' + keys.map(k => k.padEnd(colWidths[k])).join(' | ') + ' |';
    const body = rows.map(row => 
      '| ' + keys.map(k => String(row[k] ?? 'NULL').padEnd(colWidths[k])).join(' | ') + ' |'
    ).join('\n');

    return `${separator}\n${header}\n${separator}\n${body}\n${separator}\n${rows.length} row${rows.length > 1 ? 's' : ''} in set`;
  }

  return JSON.stringify(res, null, 2);
}

window.runMySQLCode = async function(buttonEl) {
  const island = buttonEl.closest('.mysql-island') || buttonEl.closest('.code-island');
  if (!island) return;

  const sourceArea = island.querySelector('.mysqlsource textarea') || island.querySelector('.code-source textarea');
  const outputPre = island.querySelector('.mysqlterm pre') || island.querySelector('.code-term pre');
  const termContainer = island.querySelector('.mysqlterm');
  if (!sourceArea || !outputPre) return;

  buttonEl.disabled = true;
  const originalText = buttonEl.innerHTML;
  buttonEl.innerHTML = 'Running...';

  try {
    const mod = await window.ensureMySQL();

    const rawCode = sourceArea.value.trim();
    const cleanCode = rawCode
      .replace(/--.*$/gm, '')
      .replace(/\/\*[\s\S]*?\*\//g, '');

    const queries = cleanCode
      .split(';')
      .map(q => q.trim())
      .filter(q => q.length > 0);

    let finalOutputs = [];

    for (const query of queries) {
      try {
        const res = await executeSingleQuery(mod, query);
        const formatted = formatSQLResults(res, query);
        finalOutputs.push(`mysql> ${query};\n${formatted}`);
      } catch (queryErr) {
        finalOutputs.push(`mysql> ${query};\nERROR: ${queryErr.message}`);
      }
    }

    const newLog = finalOutputs.join('\n\n');
    if (newLog) {
      const currentHistory = outputPre.textContent.trim();
      outputPre.textContent = currentHistory ? (currentHistory + '\n\n' + newLog) : newLog;
    }

    if (termContainer) {
      termContainer.scrollTop = termContainer.scrollHeight;
    }
  } catch (err) {
    const currentHistory = outputPre.textContent.trim();
    const errLog = `mysql> ERROR: ${err.message}`;
    outputPre.textContent = currentHistory ? (currentHistory + '\n\n' + errLog) : errLog;
    if (termContainer) {
      termContainer.scrollTop = termContainer.scrollHeight;
    }
  } finally {
    buttonEl.disabled = false;
    buttonEl.innerHTML = originalText;
  }
};