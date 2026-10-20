# bsim85 Native C Integration & Architecture Manual

This document details the interface contracts between the **C 8085 Core Engine** and the **HTML/CSS/JS WebView Frontend**.

---

## 1. System Memory & Port Mapping

| Bus / Range | Peripheral / Target | Frontend Component | Update Function |
| :--- | :--- | :--- | :--- |
| **0x0000 - 0xFFFF** | Main Addressable RAM / ROM | Memory Inspector Drawer | `bsim85.updateMemory()` |
| **Port 00H - 0FH** | 8-Bit Logic Output Ports | Logic LED Workbench Rows | `bsim85.updatePort()` |
| **Port FEH** | 7-Segment Display (Low Byte / D1:D0) | 16-Bit LCD Display | `bsim85.updatePort()` or `update7Seg()` |
| **Port FFH** | 7-Segment Display (High Byte / D3:D2) | 16-Bit LCD Display | `bsim85.updatePort()` or `update7Seg()` |
| **Internal PSW** | Sign, Zero, AuxCarry, Parity, Carry | Condition Flag LEDs + Hex tag | `bsim85.setFlags()` or `updateCpu()` |

---

## 2. Recommended C Data Structures

Define your CPU and system state cleanly in C:

```c
#include <stdint.h>
#include <stdbool.h>

// 8085 Architectural Register Bank
typedef struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t pc;
    uint16_t sp;
    uint8_t flags; // D7=S, D6=Z, D5=0, D4=AC, D3=0, D2=P, D1=1, D0=CY
} CPU8085;

// Complete 8085 System Board
typedef struct {
    CPU8085 cpu;
    uint8_t ram[65536]; // 64 KB Address Space
    uint8_t io[256];     // 256 I/O Ports
    bool is_running;
    bool is_halted;
} System8085;