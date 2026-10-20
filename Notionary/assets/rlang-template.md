<link rel="stylesheet" href="./styles/rlang.css">
<div class="webr-sandbox-wrapper code-sandbox-wrapper">
  <div class="webr-status-badge">
    <span class="webr-status-dot"></span>
    <span class="webr-status-text">Waiting</span>
  </div>

  <div class="webr-island code-island">
    <div class="webr-island-header code-island-header">
      <div class="webr-header-left code-header-left">
        <span class="webr-island-title code-island-title">R Sandbox</span>
      </div>
      <button class="webr-run-btn" onclick="runWebRCode(this)">▶ Run</button>
    </div>
    <div class="webr-island-body code-island-body">
      <div class="webrsource code-source">
        <div class="webr-gutter code-gutter">1</div>
        <textarea 
          spellcheck="false" 
          placeholder="Write R code here..." 
          oninput="updateCodeGutter(this)" 
          onscroll="syncCodeGutterScroll(this)"
        >x <- c(10, 20, 30, 40)
mean(x)</textarea>
      </div>
      <div class="webr-outputs-wrapper">
        <div class="webrterm code-term">
          <pre class="webr-output"></pre>
        </div>
        <div class="webr-plot-container">
          <button class="webr-plot-download-btn" onclick="downloadWebRPlot(this)" title="Download plot as PNG">
            <svg width="14" height="14" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
              <path d="M21 15v4a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2v-4"></path>
              <polyline points="7 10 12 15 17 10"></polyline>
              <line x1="12" y1="15" x2="12" y2="3"></line>
            </svg>
            Download
          </button>
          <canvas class="webr-plot-canvas" width="600" height="400"></canvas>
        </div>
      </div>
    </div>
  </div>
</div>