# Flip FLops & Counters &mdash; Module 1

<link rel="stylesheet" href="./styles/tables.css" >

## Definition of a Latch
---
A Latch is an asynchronous sequential circuit which stores a single bit of binary data and holds it till input combinations update.  
Latches are **Level Sensitive**, meaning their outputs are in direct correspondence to their inputs.  
**Example:** SR Latch, D Latch.

#### Applications
- Used for making flip-flops
- Used for making switch debouncing circuits.
- Used as fundamental data storage elements.

## Definition of a Flip-Flop
---
A **Flip Flop** is a basic memory element used in digital systems and electronics. It is a sequential circuit which is capable of storing a single bit of data. The output of a Flip-Flop circuit depends not only on the current state of the inputs but also on the previous state of the Flip-Flop.  
They are **Edge Triggered** circuits which update once per clock cycle.  

## Clock Cycle
---
A **Clock Cycle** refers to all the phases that a clock signal is in when it completes a cycle from 0 to 1 to 0 again.

- **Initial State:** The Clock Starts at 0, this is the  assumed initial state for any clock cycle.

- **Rising Edge:** The `x` amount of time taken when the clock transitions from 0 to 1 , in ideal digital circuits, the transition time is 0 but, in reality due to physical factors like propagation delay, the time is not exactly 0.
- **High Level:** The `x` amount of time, the clock signal remains 1, this depends on the frequency of the clock. 
- **Falling Edge:** The `x` amount of time taken when the clock transitions from 1 back to 0, in ideal digital circuits this time is 0 however, in reality due to physical factors like propagation delays, the time is not exactly 0.
- **Low Level:** The state reached by the clock signal after completing a full clock cycle, the initial state and Low Level are synonymous as the Low Level of the current cycle is the initial State of the next cycle.  

<br>
<figure align="center">
<img src="https://i.postimg.cc/J7FmJ6HC/Clock-Cycle.png">
<figcaption>Clock Cycle Representation</figcaption>
</figure>

## SR Flip Flop
---

An SR Flip Flop is fundamental memory unit capable of storing a single bit of data. It has two inputs `S` and `R` which stand for `Set` and `Reset` respectively and an output `Q`, It also has an additional output Q&#773; which is the complement of Q. The SR Flip Flop is a clocked or synchronous sequential circuit.  

#### Working of the SR Flip-Flop
- If **S = 0 and R = 1** &mdash; The Output Q is 0 while Q&#773; is 1, This state is called **Reset State**

- If **S = 1 and R = 0** &mdash; The Output Q is 1 while Q&#773; is 0, This state is called **Set State**
- If **S = 0 and R = 0** &mdash; The Circuit retains its previous state (Data is stored), This state is called **Hold State**
- If **S = 1 and R = 1** &mdash; The circuit enters an invalid state and in physical hardware, Q or Q&#773; is randomly 1 due to physical factors like propagation delay. As the end result is completely random, this state is called as **Invalid Sate**

#### Applications of SR Flip Flop

- Used in manufacturing of other flip flops
- Used in making CPU Registers
- Used in switch debouncing circuits

#### Circuit Diagram

<figure align="center">
<img src="https://i.postimg.cc/90DhKTKC/SR-FLIP-FLOP.png">
<figcaption>SR Flip Flop Circuit Diagram</figcaption>
</figure>

#### Truth Table

<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>S</th>
        <th>R</th>
        <th>Q<sub>n+1</sub></th>
        <th>State</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>0</td>
        <td>0</td>
        <td>Q<sub>n</sub></td>
        <td>Hold</td>
      </tr>
      <tr>
        <td>0</td>
        <td>1</td>
        <td>0</td>
        <td>Reset</td>
      </tr>
      <tr>
        <td>1</td>
        <td>0</td>
        <td>1</td>
        <td>Set</td>
      </tr>
      <tr>
        <td>1</td>
        <td>1</td>
        <td>X</td>
        <td>Invalid</td>
      </tr>
    </tbody>
  </table>
</div>

> Here Q<sub>n</sub> is the current state of the Flip-Flop while Q<sub>n+1</sub> is the next state.

## JK Flip Flop
---

The JK Flip Flop is an improvement over the SR Flip Flop, it has two inputs `J` and `K` and functions very similarly to the SR Flip FLop but, the JK Flip Flop does not go in an invalid state when both inputs J and K are high, instead it toggles the output pins.  
It is named JK Flip Flop because it was designed by **Jack Kilby**, the names J and K have no technical meaning.

#### Working of the JK Flip Flop

- If **J = 0 and K = 1** &mdash; The Output Q is 0 while Q&#773; is 1, This state is called **Reset State**

- If **J = 1 and K = 0** &mdash; The Output Q is 1 while Q&#773; is 0, This state is called **Set State**
- If **J = 0 and K = 0** &mdash; The Circuit retains its previous state (Data is stored), This state is called **Hold State**
- If **J = 1 and K = 1** &mdash; The circuit toggles the Output Q , if Q<sub>n</sub> = 1  the, Q<sub>n+1</sub> = 0 , similarly , if Q<sub>n</sub> = 0  the, Q<sub>n+1</sub> = 1 where,  Q<sub>n</sub> is the current state of the Flip-Flop while Q<sub>n+1</sub> is the next state.

#### Applications of JK Flip Flop
- Used for making counters
- Used for making registers
- Used in switch debouncing circuits
- Used in making T Flip Flops

#### Circuit Diagram

<figure align="center">
<img src="https://i.postimg.cc/xCTYGBPT/JK-FLi-P-FLOP.png">
<figcaption>JK Flip Flop Circuit Diagram</figcaption>
</figure>

#### Truth Table

<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>J</th>
        <th>K</th>
        <th>Q<sub>n+1</sub></th>
        <th>State</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>0</td>
        <td>0</td>
        <td>Q<sub>n</sub></td>
        <td>Hold</td>
      </tr>
      <tr>
        <td>0</td>
        <td>1</td>
        <td>0</td>
        <td>Reset</td>
      </tr>
      <tr>
        <td>1</td>
        <td>0</td>
        <td>1</td>
        <td>Set</td>
      </tr>
      <tr>
        <td>1</td>
        <td>1</td>
        <td><span style="text-decoration: overline;">Q<sub>n</sub></span></td>
        <td>Toggle</td>
      </tr>
    </tbody>
  </table>
</div>


## D Flip Flop
---

The D Flip Flop is the most commonly used flip flop for manufacturing storage devices like Registers. It stands for Data or Delay Flip Flop. Data because it can store a single bit of data and delay because it can delay the circuit by an entire clock cycle.  
It has a single input `D` and a clock signal, The state of the flip-flop reflects the state of the input `D`, and it updates once every clock pulse. 

The D Flip Flop doesn't have a traditional hold state and must be paired with a **2 - To - 1 Multiplexer** to actually achieve data storage.  

#### Working of D Flip Flop
- if **D = 0** , Output Q = 0, Q&#773; = 1

- if **D = 1** , Output Q = 1, Q&#773; = 0

The state of a D flip flop updates every clock clock cycle unless it is paired with a 2 - To - 1 Multiplexer to achieve data persistency

#### Application of D Flip Flops
- Used in manufacturing of CPU Registers
- Used in timing & delay circuits

#### Circuit Diagram

<figure align="center">
<img src="https://i.postimg.cc/tTSbBDSH/D-Flip-Flop.png">
<figcaption>D Flip Flop Circuit Diagram</figcaption>
</figure>

#### Truth Table
<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>D</th>
        <th>Q<sub>n+1</sub></th>
        <th>State</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>0</td>
        <td>0</td>
        <td>Reset</td>
      </tr>
      <tr>
        <td>1</td>
        <td>1</td>
        <td>Set</td>
      </tr>
    </tbody>
  </table>
</div>

## Ripple Counter
---
A 4 Bit Ripple Counter is a Sequential Circuit which counts from `00H` to `0FH` or `0000b` to `1111b`,it is made using 4 distinct JK Flip Flops Wired Together or 4 distinct T Flip Flops.  
It is an asynchronous counter, hence only FF0 receives the clock input and the output of the first flip flop triggers the state of the subsequent flip flops. 

#### Circuit Diagram

<figure align="center">
<img src="https://i.postimg.cc/ZK8CYz0L/Ripple-Counter.png">
<figcaption>4 Bit Ripple Up Counter</figcaption>
</figure>

#### Truth Table

<div class="dyntable">
  <table>
    <thead>
      <tr>
        <th>Clock Phase</th>
        <th>B3</th>
        <th>B2</th>
        <th>B1</th>
        <th>B0</th>
        <th>Decimal Value</th>
      </tr>
    </thead>
    <tbody>
      <tr><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td><td>0</td></tr>
      <tr><td>1</td><td>0</td><td>0</td><td>0</td><td>1</td><td>1</td></tr>
      <tr><td>2</td><td>0</td><td>0</td><td>1</td><td>0</td><td>2</td></tr>
      <tr><td>3</td><td>0</td><td>0</td><td>1</td><td>1</td><td>3</td></tr>
      <tr><td>4</td><td>0</td><td>1</td><td>0</td><td>0</td><td>4</td></tr>
      <tr><td>5</td><td>0</td><td>1</td><td>0</td><td>1</td><td>5</td></tr>
      <tr><td>6</td><td>0</td><td>1</td><td>1</td><td>0</td><td>6</td></tr>
      <tr><td>7</td><td>0</td><td>1</td><td>1</td><td>1</td><td>7</td></tr>
      <tr><td>8</td><td>1</td><td>0</td><td>0</td><td>0</td><td>8</td></tr>
      <tr><td>9</td><td>1</td><td>0</td><td>0</td><td>1</td><td>9</td></tr>
      <tr><td>10</td><td>1</td><td>0</td><td>1</td><td>0</td><td>10</td></tr>
      <tr><td>11</td><td>1</td><td>0</td><td>1</td><td>1</td><td>11</td></tr>
      <tr><td>12</td><td>1</td><td>1</td><td>0</td><td>0</td><td>12</td></tr>
      <tr><td>13</td><td>1</td><td>1</td><td>0</td><td>1</td><td>13</td></tr>
      <tr><td>14</td><td>1</td><td>1</td><td>1</td><td>0</td><td>14</td></tr>
      <tr><td>15</td><td>1</td><td>1</td><td>1</td><td>1</td><td>15</td></tr>
    </tbody>
  </table>
</div>

<br>


*&mdash; Edited By Baibhav Bhattacharya*