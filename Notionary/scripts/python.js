let pyodideInstance = null;
window.__isPyodideLoading = false;
window.__isPyodideReady = false;

function updatePyodideBadges(status) {
  document.querySelectorAll('.py-status-badge').forEach(function(badge) {
    if (status === 'ready') {
      badge.className = 'py-status-badge ready';
      badge.querySelector('.py-status-text').textContent = 'Python Ready';
    } else if (status === 'loading') {
      badge.className = 'py-status-badge';
      badge.querySelector('.py-status-text').textContent = 'Initializing...';
    } else {
      badge.className = 'py-status-badge';
      badge.querySelector('.py-status-text').textContent = 'Waiting...';
    }
  });
}

async function ensurePyodide() {
  if (window.__isPyodideReady) return pyodideInstance;
  if (window.__isPyodideLoading) {
    while (!window.__isPyodideReady) {
      await new Promise(r => setTimeout(r, 100));
    }
    return pyodideInstance;
  }

  window.__isPyodideLoading = true;
  updatePyodideBadges('loading');

  try {
    if (!window.loadPyodide) {
      await new Promise((resolve, reject) => {
        const s = document.createElement('script');
        s.src = 'https://cdn.jsdelivr.net/pyodide/v0.25.0/full/pyodide.js';
        s.onload = resolve;
        s.onerror = reject;
        document.head.appendChild(s);
      });
    }
    pyodideInstance = await loadPyodide();
    window.__isPyodideReady = true;
    window.__isPyodideLoading = false;
    updatePyodideBadges('ready');
    return pyodideInstance;
  } catch (err) {
    window.__isPyodideLoading = false;
    console.error('Failed to load Pyodide:', err);
    throw err;
  }
}

async function runPythonCode(buttonEl) {
  const island = buttonEl.closest('.code-island') || buttonEl.closest('.py-island');
  if (!island) return;

  const sourceArea = island.querySelector('.code-source textarea') || island.querySelector('.pysource textarea');
  const outputPre = island.querySelector('.code-term pre') || island.querySelector('.pyterm pre');
  if (!sourceArea || !outputPre) return;

  buttonEl.disabled = true;
  const originalText = buttonEl.innerHTML;
  buttonEl.innerHTML = 'Running...';
  outputPre.className = 'py-output';
  outputPre.textContent = 'Loading packages...';

  try {
    const py = await ensurePyodide();
    await py.loadPackagesFromImports(sourceArea.value);

    outputPre.textContent = 'Executing...';

    py.setStdin({
      stdin: () => {
        const res = window.prompt("Python input():");
        return res !== null ? res + "\n" : "\n";
      }
    });

    let code = sourceArea.value;
    const inputMatches = [...code.matchAll(/input\s*\(\s*(?:["'](.*?)["'])?\s*\)/g)];
    const userValues = [];
    for (const match of inputMatches) {
      const promptText = match[1] || "Enter value:";
      const userInput = await requestSandboxInput(promptText, "Python Input Prompt", false);
      userValues.push(userInput);
    }

    let pyInputIdx = 0;
    code = code.replace(/input\s*\(\s*(?:["'](.*?)["'])?\s*\)/g, () => {
      return JSON.stringify(userValues[pyInputIdx++]);
    });

    py.runPython(`
import sys
import io
sys.stdout = io.StringIO()
sys.stderr = io.StringIO()
`);
    const result = await py.runPythonAsync(code);
    let stdout = py.runPython("sys.stdout.getvalue()");
    let stderr = py.runPython("sys.stderr.getvalue()");

    let finalOutput = '';
    if (stdout) finalOutput += stdout;
    if (stderr) finalOutput += (finalOutput ? '\n' : '') + stderr;
    if (result !== undefined && result !== null) {
      finalOutput += (finalOutput ? '\n' : '') + String(result);
    }

    outputPre.textContent = finalOutput.trim() || '(Execution completed with no output)';
  } catch (err) {
    outputPre.className = 'py-output py-err';
    outputPre.textContent = err.message;
  } finally {
    buttonEl.disabled = false;
    buttonEl.innerHTML = originalText;
  }
}

window.ensurePyodide = ensurePyodide;
window.runPythonCode = runPythonCode;
window.updatePyodideBadges = updatePyodideBadges;