/**
 * Limitless Archive - WebR Runner Module
 */
let webrInstance = null;
window.__isWebRLoading = false;
window.__isWebRReady = false;

window.updateWebRBadges = function(status) {
  document.querySelectorAll('.webr-status-badge').forEach(function(badge) {
    if (status === 'ready') {
      badge.className = 'webr-status-badge ready';
      badge.querySelector('.webr-status-text').textContent = 'R Ready';
    } else if (status === 'loading') {
      badge.className = 'webr-status-badge';
      badge.querySelector('.webr-status-text').textContent = 'Initializing...';
    } else {
      badge.className = 'webr-status-badge';
      badge.querySelector('.webr-status-text').textContent = 'Waiting...';
    }
  });
};

window.ensureWebR = async function() {
  if (window.__isWebRReady) return webrInstance;
  if (window.__isWebRLoading) {
    while (!window.__isWebRReady) {
      await new Promise(r => setTimeout(r, 100));
    }
    return webrInstance;
  }

  window.__isWebRLoading = true;
  window.updateWebRBadges('loading');

  try {
    const { WebR } = await import('https://webr.r-wasm.org/v0.3.3/webr.mjs');
    webrInstance = new WebR();
    await webrInstance.init();
    window.__isWebRReady = true;
    window.__isWebRLoading = false;
    window.updateWebRBadges('ready');
    return webrInstance;
  } catch (err) {
    window.__isWebRLoading = false;
    console.error('Failed to load WebR:', err);
    throw err;
  }
};

window.runWebRCode = async function(buttonEl) {
  const island = buttonEl.closest('.webr-island') || buttonEl.closest('.code-island');
  if (!island) return;

  const sourceArea = island.querySelector('.webrsource textarea') || island.querySelector('.code-source textarea');
  const outputPre = island.querySelector('.webrterm pre') || island.querySelector('.code-term pre');
  const plotContainer = island.querySelector('.webr-plot-container');
  const plotCanvas = island.querySelector('.webr-plot-canvas');

  if (!sourceArea || !outputPre) return;

  buttonEl.disabled = true;
  const originalText = buttonEl.innerHTML;
  buttonEl.innerHTML = 'Running...';
  outputPre.className = 'webr-output';
  outputPre.textContent = 'Executing...';

  if (plotContainer) {
    plotContainer.classList.remove('has-plot');
  }
  if (plotCanvas) {
    const ctx = plotCanvas.getContext('2d');
    ctx.clearRect(0, 0, plotCanvas.width, plotCanvas.height);
  }

  try {
    const r = await window.ensureWebR();
    let code = sourceArea.value;

    const readlineMatches = [...code.matchAll(/readline\s*\(\s*(?:prompt\s*=\s*)?["'](.*?)["']\s*\)/g)];
    const rValues = [];
    for (const match of readlineMatches) {
      const promptText = match[1] || "Enter R input:";
      const userInput = await requestSandboxInput(promptText, "R Input Prompt", true);
      rValues.push(userInput);
    }

    let rInputIdx = 0;
    code = code.replace(/readline\s*\(\s*(?:prompt\s*=\s*)?["'](.*?)["']\s*\)/g, () => {
      return JSON.stringify(rValues[rInputIdx++]);
    });

    const shelter = await new r.Shelter();
    const capture = await shelter.captureR(code, {
      withAutoprint: true,
      captureStreams: true,
      captureConditions: true,
      captureGraphics: true
    });

    let outputText = '';
    if (capture.output && capture.output.length > 0) {
      outputText = capture.output
        .filter(item => item.type === 'stdout' || item.type === 'stderr')
        .map(item => item.data)
        .join('\n');
    }

    if (capture.images && capture.images.length > 0 && plotCanvas && plotContainer) {
      const lastImg = capture.images[capture.images.length - 1];
      if (lastImg) {
        plotCanvas.width = lastImg.width || 600;
        plotCanvas.height = lastImg.height || 400;
        const ctx = plotCanvas.getContext('2d');
        ctx.drawImage(lastImg, 0, 0);
        plotContainer.classList.add('has-plot');
      }
    }

    await shelter.purge();
    outputPre.textContent = outputText.trim() || '(Execution completed with no output)';
  } catch (err) {
    outputPre.className = 'webr-output webr-err';
    outputPre.textContent = err.message;
  } finally {
    buttonEl.disabled = false;
    buttonEl.innerHTML = originalText;
  }
};