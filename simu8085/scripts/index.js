//Syntax Highlight
const ASM85_RULES = [
  { type: 'syn-comment', regex: /(;.*$)/gm },
  { type: 'syn-string', regex: /('[^']*'|"[^"]*")/g },
  { type: 'syn-label', regex: /\b([A-Za-z_][A-Za-z0-9_]*):/g },
  {
    type: 'syn-keyword',
    regex: /\b(ACI|ADC|ADD|ADI|ANA|ANI|CALL|CC|CNC|CNZ|CP|CPE|CPO|CZ|CMA|CMC|CMP|CPI|DAA|DAD|DCR|DCX|DI|EI|HLT|IN|INR|INX|JC|JM|JMP|JNC|JNZ|JP|JPE|JPO|JZ|LDA|LDAX|LHLD|LXI|MOV|MVI|NOP|ORA|ORI|OUT|PCHL|POP|PUSH|RAL|RAR|RC|RET|RIM|RLC|RM|RNC|RNZ|RP|RPE|RPO|RRC|RST|RZ|SBB|SBI|SHLD|SIM|SPHL|STA|STAX|STC|SUB|SUI|XCHG|XRA|XRI|XTHL|ORG|EQU|DB|DW|DS|END)\b/gi
  },
  { type: 'syn-register', regex: /\b(A|B|C|D|E|H|L|M|PSW|SP|PC)\b/gi },
  { type: 'syn-number', regex: /\b([0-9][0-9A-Fa-f]*H|0x[0-9A-Fa-f]+|\d+)\b/gi }
];

function highlightAssembly(code) {
  let html = code
    .replace(/&/g, '&amp;')
    .replace(/</g, '&lt;')
    .replace(/>/g, '&gt;');

  ASM85_RULES.forEach(rule => {
    html = html.replace(rule.regex, (match) => `<span class="${rule.type}">${match}</span>`);
  });

  return html.endsWith('\n') ? html + ' ' : html;
}


function setActivePanel(panelId) {
  document.querySelectorAll('.activity-bar .rail-btn:not(#btn-stage-terminal):not(#btn-theme-toggle)').forEach(btn => {
    btn.classList.remove('active');
  });
  const activeBtn = document.getElementById('btn-view-' + panelId);
  if (activeBtn) activeBtn.classList.add('active');

  document.querySelectorAll('.panel-stage .drawer-view').forEach(panel => {
    panel.classList.remove('active');
  });
  const activePanel = document.getElementById('panel-' + panelId);
  if (activePanel) activePanel.classList.add('active');
}

function toggleStageMode() {
  const editor = document.getElementById('stage-editor');
  const terminal = document.getElementById('stage-terminal');
  const termBtn = document.getElementById('btn-stage-terminal');
  const indicator = document.getElementById('toolbar-mode-indicator');

  if (terminal.classList.contains('active')) {
    terminal.classList.remove('active');
    editor.classList.add('active');
    termBtn.classList.remove('active');
    indicator.textContent = "Assembly Editor";
  } else {
    editor.classList.remove('active');
    terminal.classList.add('active');
    termBtn.classList.add('active');
    indicator.textContent = "Debug Terminal";
    document.getElementById('terminal-input').focus();
  }
}

function toggleHardwarePanel() {
  document.getElementById('hardware-panel').classList.toggle('collapsed');
}

function toggleTheme() {
  const html = document.documentElement;
  const nextTheme = html.getAttribute('data-theme') === 'dark' ? 'light' : 'dark';
  html.setAttribute('data-theme', nextTheme);
}


function onAssemble() {
  const code = document.getElementById('code-area').value;
  if (window.assembleCode) {
    window.assembleCode(code);
  } else {
    window.bsim85.logTerminal('[SYS] assembleCode binding not connected to C.', 'error');
  }
}

function onStep() {
  if (window.stepCpu) {
    window.stepCpu();
  } else {
    window.bsim85.logTerminal('[SYS] stepCpu binding not connected to C.', 'error');
  }
}

function onRun() {
  if (window.runCpu) {
    window.runCpu();
  } else {
    window.bsim85.logTerminal('[SYS] runCpu binding not connected to C.', 'error');
  }
}

function onResetCpu() {
  const resetBtn = document.getElementById('btn-reset');
  const icon = resetBtn ? resetBtn.querySelector('.btn-icon') : null;
  if (icon) {
    icon.classList.remove('spin-animate');
    // Force DOM reflow to re-trigger animation on consecutive presses
    void icon.offsetWidth;
    icon.classList.add('spin-animate');
  }

  // Trigger C native binding if present
  if (typeof window.resetCpu === 'function') {
    window.resetCpu();
  } else if (typeof window.Module !== 'undefined' && typeof window.Module._c_reset_cpu === 'function') {
    window.Module._c_reset_cpu();
  } else {
    window.bsim85.resetUI();
    window.bsim85.logTerminal('[CPU] System Hardware Reset (JS Native Fallback applied).', 'info');
  }
}

function sendHexKey(key) {
  // Update 3-byte 7-segment display for trainer keys
  if (window.bsim85 && window.bsim85.handleKeyOnDisplay) {
    window.bsim85.handleKeyOnDisplay(key);
  }

  if (key === 'RST') {
    onResetCpu();
  }

  if (window.onHexKeyPress) {
    window.onHexKeyPress(key);
  } else {
    window.bsim85.logTerminal(`[KEYPAD] Key pressed: ${key}`, 'info');
  }
}

document.addEventListener('DOMContentLoaded', () => {
  // 1. Build Port LED strips (Ports 00H-0FH)
  const portsContainer = document.getElementById('all-ports-container');
  if (portsContainer) {
    for (let p = 0; p <= 0x0F; p++) {
      const hexPort = p.toString(16).toUpperCase().padStart(2, '0');
      const strip = document.createElement('div');
      strip.className = 'port-strip';
      strip.id = `port-strip-${p}`;

      let ledsHtml = '';
      for (let b = 7; b >= 0; b--) {
        ledsHtml += `<div class="led-bulb" id="led-${p}-${b}" title="Bit ${b}"></div>`;
      }

      strip.innerHTML = `
        <span class="port-strip-label">${hexPort}H</span>
        <div class="port-strip-leds">${ledsHtml}</div>
        <span class="port-strip-val" id="port-val-${p}">0x00</span>
      `;
      portsContainer.appendChild(strip);
    }
  }

  // 2. Toolbar Actions
  document.getElementById('btn-reset').addEventListener('click', onResetCpu);
  document.getElementById('btn-assemble').addEventListener('click', onAssemble);
  document.getElementById('btn-step').addEventListener('click', onStep);
  document.getElementById('btn-run').addEventListener('click', onRun);

  // 3. Navigation Actions
  document.getElementById('btn-view-registers').addEventListener('click', () => setActivePanel('registers'));
  document.getElementById('btn-view-memory').addEventListener('click', () => setActivePanel('memory'));
  document.getElementById('btn-view-io').addEventListener('click', () => setActivePanel('io'));
  document.getElementById('btn-stage-terminal').addEventListener('click', toggleStageMode);
  document.getElementById('btn-theme-toggle').addEventListener('click', toggleTheme);
  document.getElementById('hw-toggle-btn').addEventListener('click', toggleHardwarePanel);

  // 4. Hex Keypad
  document.querySelectorAll('.keypad-btn').forEach(btn => {
    btn.addEventListener('click', () => {
      const key = btn.getAttribute('data-key');
      if (key) sendHexKey(key);
    });
  });

  // 5. Memory Query Input
  document.getElementById('mem-base-input').addEventListener('change', (e) => {
    if (window.queryMemory) window.queryMemory(e.target.value);
  });

  // 6. Terminal Command Input
  document.getElementById('terminal-input').addEventListener('keydown', (e) => {
    if (e.key === 'Enter') {
      const input = e.target;
      const val = input.value.trim();
      if (!val) return;
      window.bsim85.logTerminal(`bsim85> ${val}`, 'command');
      if (val.toLowerCase() === 'reset' || val.toLowerCase() === 'rst') {
        onResetCpu();
      } else if (window.execTerminalCmd) {
        window.execTerminalCmd(val);
      } else if (val === 'clear') {
        document.getElementById('terminal-out').innerHTML = '';
      } else {
        window.bsim85.logTerminal(`Command not recognized: ${val}`, 'error');
      }
      input.value = '';
    }
  });

  // 7. Editor Synchronization
  const codeArea = document.getElementById('code-area');
  const highlightCode = document.getElementById('highlight-code');
  const highlightLayer = document.getElementById('highlight-layer');
  const gutter = document.getElementById('gutter');

  const updateEditor = () => {
    const text = codeArea.value;
    highlightCode.innerHTML = highlightAssembly(text);
    const lines = text.split('\n').length;
    gutter.innerHTML = Array.from({ length: lines }, (_, i) => `<div>${i + 1}</div>`).join('');
  };

  const syncScroll = () => {
    highlightLayer.scrollTop = codeArea.scrollTop;
    highlightLayer.scrollLeft = codeArea.scrollLeft;
    gutter.scrollTop = codeArea.scrollTop;
  };

  codeArea.addEventListener('input', updateEditor);
  codeArea.addEventListener('scroll', syncScroll);

  updateEditor();
});