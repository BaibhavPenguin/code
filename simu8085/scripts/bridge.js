(function () {
  const segmentMap = {
    '0': ['a', 'b', 'c', 'd', 'e', 'f'],
    '1': ['b', 'c'],
    '2': ['a', 'b', 'g', 'e', 'd'],
    '3': ['a', 'b', 'g', 'c', 'd'],
    '4': ['f', 'g', 'b', 'c'],
    '5': ['a', 'f', 'g', 'c', 'd'],
    '6': ['a', 'f', 'e', 'd', 'c', 'g'],
    '7': ['a', 'b', 'c'],
    '8': ['a', 'b', 'c', 'd', 'e', 'f', 'g'],
    '9': ['a', 'b', 'c', 'd', 'f', 'g'],
    'A': ['a', 'b', 'c', 'e', 'f', 'g'],
    'B': ['c', 'd', 'e', 'f', 'g'],
    'C': ['a', 'd', 'e', 'f'],
    'D': ['b', 'c', 'd', 'e', 'g'],
    'E': ['a', 'd', 'e', 'f', 'g'],
    'F': ['a', 'e', 'f', 'g'],
    ' ': [],
    '-': ['g']
  };

  const toHex2 = (n) => (n !== undefined && n !== null ? (n & 0xff).toString(16).toUpperCase().padStart(2, '0') : '--');
  const toHex4 = (n) => (n !== undefined && n !== null ? (n & 0xffff).toString(16).toUpperCase().padStart(4, '0') : '----');

  window.bsim85 = {
    portMemory: new Uint8Array(256),
    displayAddr: 0x2000,
    displayData: 0x00,

    updateCpu: function (s) {
      if (!s) return;

      if (s.a !== undefined) this.setRegister('A', s.a);
      if (s.b !== undefined) this.setRegister('B', s.b);
      if (s.c !== undefined) this.setRegister('C', s.c);
      if (s.d !== undefined) this.setRegister('D', s.d);
      if (s.e !== undefined) this.setRegister('E', s.e);
      if (s.h !== undefined) this.setRegister('H', s.h);
      if (s.l !== undefined) this.setRegister('L', s.l);

      if (s.b !== undefined || s.c !== undefined) {
        const b = s.b !== undefined ? s.b : parseInt(document.getElementById('reg-b').textContent || '0', 16);
        const c = s.c !== undefined ? s.c : parseInt(document.getElementById('reg-c').textContent || '0', 16);
        document.getElementById('pair-bc').textContent = '0x' + toHex2(b) + toHex2(c);
      }

      if (s.d !== undefined || s.e !== undefined) {
        const d = s.d !== undefined ? s.d : parseInt(document.getElementById('reg-d').textContent || '0', 16);
        const e = s.e !== undefined ? s.e : parseInt(document.getElementById('reg-e').textContent || '0', 16);
        document.getElementById('pair-de').textContent = '0x' + toHex2(d) + toHex2(e);
      }

      if (s.h !== undefined || s.l !== undefined) {
        const h = s.h !== undefined ? s.h : parseInt(document.getElementById('reg-h').textContent || '0', 16);
        const l = s.l !== undefined ? s.l : parseInt(document.getElementById('reg-l').textContent || '0', 16);
        document.getElementById('pair-hl').textContent = '0x' + toHex2(h) + toHex2(l);
      }

      if (s.pc !== undefined) this.setPC(s.pc);
      if (s.sp !== undefined) this.setSP(s.sp);
      if (s.flags !== undefined) this.setFlags(s.flags);
    },

    setRegister: function (name, val) {
      const el = document.getElementById(`reg-${name.toLowerCase()}`);
      if (el) el.textContent = toHex2(val);
    },

    setPC: function (val) {
      const el = document.getElementById('reg-pc');
      if (el) el.textContent = '0x' + toHex4(val);
    },

    setSP: function (val) {
      const el = document.getElementById('reg-sp');
      if (el) el.textContent = '0x' + toHex4(val);
    },

    setFlags: function (f) {
      f = f & 0xff;
      const toggleLed = (id, active) => {
        const el = document.querySelector(`#${id} .led`);
        if (el) el.classList.toggle('active', active);
      };

      toggleLed('flag-s', !!(f & 0x80));
      toggleLed('flag-z', !!(f & 0x40));
      toggleLed('flag-ac', !!(f & 0x10));
      toggleLed('flag-p', !!(f & 0x04));
      toggleLed('flag-cy', !!(f & 0x01));

      const hexEl = document.getElementById('reg-flags-hex');
      if (hexEl) hexEl.textContent = '0x' + toHex2(f);
    },

    updatePort: function (portNum, val) {
      portNum = Number(portNum) & 0xff;
      val = Number(val) & 0xff;
      this.portMemory[portNum] = val;

      if (portNum <= 0x0f) {
        const hexVal = toHex2(val);
        const valEl = document.getElementById(`port-val-${portNum}`);
        if (valEl) valEl.textContent = '0x' + hexVal;

        for (let bit = 0; bit < 8; bit++) {
          const led = document.getElementById(`led-${portNum}-${bit}`);
          if (led) led.classList.toggle('active', !!(val & (1 << bit)));
        }
      }

      this.syncIoTable(portNum, val);
    },

    /**
     * Update 3-Byte 7-Segment Display (6 Hex Digits)
     * @param {number} b2 High byte (Addr High) -> Digits 5 & 4
     * @param {number} b1 Mid byte  (Addr Low)  -> Digits 3 & 2
     * @param {number} b0 Low byte  (Data byte) -> Digits 1 & 0
     */
    update7Seg: function (b2, b1, b0) {
      if (b0 === undefined) {
        // Fallback for 2-byte invocations
        b0 = b1 || 0;
        b1 = b2 || 0;
        b2 = 0;
      }
      b2 = (b2 || 0) & 0xff;
      b1 = (b1 || 0) & 0xff;
      b0 = (b0 || 0) & 0xff;

      this.renderDigit(5, ((b2 >> 4) & 0x0f).toString(16));
      this.renderDigit(4, (b2 & 0x0f).toString(16));
      this.renderDigit(3, ((b1 >> 4) & 0x0f).toString(16));
      this.renderDigit(2, (b1 & 0x0f).toString(16));
      this.renderDigit(1, ((b0 >> 4) & 0x0f).toString(16));
      this.renderDigit(0, (b0 & 0x0f).toString(16));
    },

    renderDigit: function (digitIndex, charVal) {
      const svg = document.getElementById(`seg-digit-${digitIndex}`);
      if (!svg) return;
      const activeSegs = segmentMap[charVal.toUpperCase()] || [];
      ['a', 'b', 'c', 'd', 'e', 'f', 'g'].forEach((seg) => {
        const el = svg.querySelector(`.seg-${seg}`);
        if (el) el.classList.toggle('active', activeSegs.includes(seg));
      });
    },

    /**
     * Handle keypad special key
     */
    handleKeyOnDisplay: function (key) {
      switch (key) {
        case 'INC':
          this.displayAddr = (this.displayAddr + 1) & 0xffff;
          break;
        case 'DEC':
          this.displayAddr = (this.displayAddr - 1) & 0xffff;
          break;
        case 'GO':
          // Preset to execution start
          this.displayData = 0x00;
          break;
        case 'RST':
          this.displayAddr = 0x0000;
          this.displayData = 0x00;
          break;
      }
      const b2 = (this.displayAddr >> 8) & 0xff;
      const b1 = this.displayAddr & 0xff;
      const b0 = this.displayData & 0xff;
      this.update7Seg(b2, b1, b0);
    },

    updateMemory: function (startAddr, byteArr) {
      const container = document.getElementById('memory-cells');
      if (!container || !Array.isArray(byteArr)) return;

      container.innerHTML = '';
      for (let i = 0; i < byteArr.length; i += 2) {
        const addr = toHex4(startAddr + i);
        const b1 = toHex2(byteArr[i]);
        const b2 = i + 1 < byteArr.length ? toHex2(byteArr[i + 1]) : '--';

        const div = document.createElement('div');
        div.className = 'cell';
        div.textContent = `${addr}: ${b1} ${b2}`;
        container.appendChild(div);
      }
    },

    logTerminal: function (text, type = '') {
      const out = document.getElementById('terminal-out');
      if (!out) return;
      const div = document.createElement('div');
      div.className = `term-line ${type}`;
      div.textContent = text;
      out.appendChild(div);
      out.scrollTop = out.scrollHeight;
    },

    syncIoTable: function (portNum, val) {
      const rowId = `io-port-row-${portNum}`;
      let row = document.getElementById(rowId);
      const hexPort = toHex2(portNum);
      const hexVal = toHex2(val);

      if (!row) {
        const list = document.getElementById('io-table-body');
        if (!list) return;
        row = document.createElement('div');
        row.className = 'data-row';
        row.id = rowId;
        row.innerHTML = `<span>Port ${hexPort}H</span><strong>0x${hexVal}</strong>`;
        list.appendChild(row);
      } else {
        const strong = row.querySelector('strong');
        if (strong) strong.textContent = '0x' + hexVal;
      }
    },

    resetUI: function () {
      this.updateCpu({
        a: 0x00, b: 0x00, c: 0x00, d: 0x00, e: 0x00, h: 0x00, l: 0x00,
        pc: 0x0000, sp: 0xFFFF, flags: 0x00
      });

      this.portMemory.fill(0);
      this.displayAddr = 0x0000;
      this.displayData = 0x00;
      this.update7Seg(0x00, 0x00, 0x00);

      for (let p = 0; p <= 0x0f; p++) {
        const valEl = document.getElementById(`port-val-${p}`);
        if (valEl) valEl.textContent = '0x00';
        for (let b = 0; b < 8; b++) {
          const led = document.getElementById(`led-${p}-${b}`);
          if (led) led.classList.remove('active');
        }
      }

      const mem = document.getElementById('memory-cells');
      if (mem) mem.innerHTML = '';

      const io = document.getElementById('io-table-body');
      if (io) io.innerHTML = '';

      document.querySelectorAll('.register-tile, .reg-pair-box, .flags-card').forEach((el) => {
        el.classList.remove('reset-flash');
        void el.offsetWidth;
        el.classList.add('reset-flash');
      });
    }
  };

  window.c_bridge_update_cpu = (a, b, c, d, e, h, l, pc, sp, flags) => {
    window.bsim85.updateCpu({ a, b, c, d, e, h, l, pc, sp, flags });
  };
  window.c_bridge_update_port = (port, val) => {
    window.bsim85.updatePort(port, val);
  };
  window.c_bridge_reset = () => {
    window.bsim85.resetUI();
  };
})();