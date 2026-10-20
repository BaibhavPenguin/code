# Digital Systems & Architecture

## What are Logic Gates
**Logic gates** are the fundamental physical building blocks of digital logic. Logic gates operate in **Boolean Logic** i.e. they take one or more binary inputs and produce a single output based on the state of the inputs corresponding to the underlying logical function.  
**Example:** AND Gates, OR Gates, NOR Gates.  

#### Basic Logic Gates
The basic logic gates only perform a single logical function and cannot be used in pairs to perform additional logical functions. These gates can only be made from transistors or Universal Logic Gates, Basic gates cannot be used in pair to make other basic gates.
**Example:** AND, OR, NOT, Gates are Basic Gates.  

#### Universal Logic Gates
The Universal Logic Gates can be used ine pairs to construct any logic gates. They can be created using both Combination of Basic Gates  and Transistors.  
**Example:** NAND and NOT Gates are Universal Gates.  

#### Special Logic Gates
The Special Function Logic Gates can be constructed using combinations of basic logic gates and transistors however, they cannot be used to create basic logic gates and only perform specified logical functions.  
**Example:** XOR and XNOR are the Special Function Logic Gates.

## What are Combinational Circuits
---
**Combinational Circuits** are digital logic circuits whose outputs are depend only on the current combination (logical state) of the inputs at any given moment.  
**Example:** Adders, Subtractors, Multiplexers, Demultiplexers.  

## What are Sequential Circuits
---
Sequential Circuits are logical circuits whose outputs depend on both the current values of the inputs and the past input history. Unlike combinational circuits, sequential circuits contain memory elements such as latches and flip-flops.

#### Asynchronous Sequential Circuits
These don't rely on global clock phases (time events). The state of the output of Asynchronous Sequential Circuit changes as soon as their input changes. These circuits are said to be **Transparent** as outputs directly correspond to input states. These circuits are also called as **Level Sensitive** Circuits.

#### Synchronous Sequential Circuits
The output of these circuits are synchronized with a global clock. These circuits are **Edge Triggered** and work in synch with a clock instead of a global enable pin.  

## Understanding the Clock
---
The `Clock` or `CLK` in digital logic is not the same as the wall clock in our house that tells time. The `CLK` here is used for dictating when a specific event happens.
If the time interval between two events is consistent, the clock is said to have a stable frequency. The frequency here is **how often an event happens** while the event can be anything, reading data, writing data, updating registers, etc.   
A Modern Laptop can have a 4GHz Clock Speed, this means that the CPU performs **4 Billion Events** every second. It has no relation to the actual time.

---
All Notes as per NEP 2020

* [Module 1 ](/assets/first-year/dsa/dsa-ov.md)
    * [Basic Logic Gates](/assets/first-year/dsa/logic-gates.md)
    * [Half & Full Adders](/assets/first-year/dsa/adders.md)
    * [Half & Full Subtractors](/assets/first-year/dsa/subtractor.md)
    * [Multiplexers](/assets/first-year/dsa/mux.md)
    * [Demultiplexers](/assets/first-year/dsa/demux.md)
    * [Flip Flops](/assets/first-year/dsa/flip-flops.md)
    * [Computer Systems](/assets/first-year/dsa/computer-systems.md)

> **Tracked Years** : 2026-2027

