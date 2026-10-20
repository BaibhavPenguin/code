# Demultiplexer &mdash; Module 1

<link rel="stylesheet" href="./styles/tables.css" >

A Demultiplexer is a combinational circuit which performs **data distribution** on a single input and routes/distributes it to 2<sup>n</sup> output channels, where `n = Number of Select Lines`  

It is constructed using `AND` and `NOT` Gates.

#### Applications
- It is used to manufacture Decoders
- It is used for routing data through bus
- It is used in the Control Unit of CPU
- It is used to make Register Select Circuits

---

### 1 To 2 Demultiplexer
A 1 To 2 Demultiplexer distributes a single input into 2 distinct output channels using a single select line. <code>&therefore; n = 1 , 2<sup>n</sup> = 2</code> <br>
It is the simplest form of Demultipexer.

<div class="dyntable">
<table>
  <thead>
    <tr>
      <th>S</th>
      <th>Y<sub>0</sub></th>
      <th>Y<sub>1</sub></th>
      <th>Minterm (Y<sub>0</sub>)</th>
      <th>Minterm (Y<sub>1</sub>)</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>I<sub>0</sub></td>
      <td>0</td>
      <td><span style="text-decoration: overline;">S</span>I<sub>0</sub></td>
      <td>0</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>I<sub>0</sub></td>
      <td>0</td>
      <td>SI<sub>0</sub></td>
    </tr>
  </tbody>
</table>
</div>

<figure align="center">
<img src="https://i.postimg.cc/d0ZdnTHg/1-2-DEMUX.png">
<figcaption>1 To 2 Demultiplexer Circuit Diagram</figcaption>
</figure>

<br>
<blockquote>
  Y<sub>0</sub> = <span style="text-decoration: overline;">S</span>I<sub>0</sub><br>
  Y<sub>1</sub> = SI<sub>0</sub>
</blockquote>

---

### 1 To 4 Demultiplexer
A 1 To 4 Demultiplexer distributes a single input into 4 distinct output channels using two select lines. <code>&therefore; n = 2 , 2<sup>n</sup> = 4</code> <br>



<div class="dyntable">
<table>
  <thead>
    <tr>
      <th>S<sub>1</sub></th>
      <th>S<sub>0</sub></th>
      <th>Y<sub>0</sub></th>
      <th>Y<sub>1</sub></th>
      <th>Y<sub>2</sub></th>
      <th>Y<sub>3</sub></th>
      <th>Minterms</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>I<sub>in</sub></td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>Y<sub>0</sub> = <span style="text-decoration: overline;">S</span><sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>in</sub></td>
    </tr>
    <tr>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>I<sub>in</sub></td>
      <td>0</td>
      <td>0</td>
      <td>Y<sub>1</sub> = <span style="text-decoration: overline;">S</span><sub>1</sub>S<sub>0</sub>I<sub>in</sub></td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>I<sub>in</sub></td>
      <td>0</td>
      <td>Y<sub>2</sub> = S<sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>in</sub></td>
    </tr>
    <tr>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>I<sub>in</sub></td>
      <td>Y<sub>3</sub> = S<sub>1</sub>S<sub>0</sub>I<sub>in</sub></td>
    </tr>
  </tbody>
</table>
</div>
<br>
<figure align="center">
<img src="https://i.postimg.cc/5tQvpFKc/1-2-4-DEMUX.png">
<figcaption>1 To 4 Demultiplexer Circuit Diagram</figcaption>
</figure>
<br>

<blockquote>
  Y<sub>0</sub> = <span style="text-decoration: overline;">S</span><sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>in</sub><br>
  Y<sub>1</sub> = <span style="text-decoration: overline;">S</span><sub>1</sub>S<sub>0</sub>I<sub>in</sub><br>
  Y<sub>2</sub> = S<sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>in</sub><br>
  Y<sub>3</sub> = S<sub>1</sub>S<sub>0</sub>I<sub>in</sub>
</blockquote>
<br>

*&mdash; Edited by Baibhav Bhattacharya*
