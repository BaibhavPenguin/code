# Multiplexers &mdash; Module 1

A Multiplexer is a combinational circuit which performs data selection from 2<sup>n</sup> inputs where `n = number of select lines`.   
At any point the output of the Multiplexer is EQUAL to the selected input. Hence, if the value of the selected input is 0, the output of the multiplexer will also be 0.
 
#### <u>Applications</u>  
- It is constructed using `AND` , `OR` and `NOT` gates.   
- It is used in **Control Unit** of a CPU.   
- It is used for designing **cpu registers**.    

---

### <u>2 To 1 Multiplexer</u>
A 2 To 1 Multiplexer performs data selection on 2 inputs using a single select line. It is the most basic form of Multiplexer.  

<link rel="stylesheet" href="./styles/tables.css" >

<div class="dyntable">
<table>
  <thead>
    <tr>
      <th>S</th>
      <th>Y</th>
      <th>Minterm</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>I<sub>0</sub></td>
      <td><span style="text-decoration: overline;">S</span>I<sub>0</sub></td>
    </tr>
    <tr>
      <td>1</td>
      <td>I<sub>1</sub></td>
      <td>SI<sub>1</sub></td>
    </tr>
  </tbody>
</table>
</div>

<figure align="center">
<img src="https://i.postimg.cc/pVYb95dy/2-2-1-MUX.png">
<figcaption>2 To 1 Multiplexer Circuit Diagram
</figcaption>
</figure>

> Y = S&#773;I<sub>0</sub> + SI<sub>1<sub>

---

### <u>4 To 1 Multiplexer</u>
A 4 To 1 Multiplexer performs data selection on 4 inputs I<sub>0</sub>, I<sub>1</sub>, I<sub>2</sub>, I<sub>3</sub> using two select lines S<sub>0</sub> and S<sub>1</sub>

<div class="dyntable">
<table>
  <thead>
    <tr>
      <th>S<sub>1</sub></th>
      <th>S<sub>0</sub></th>
      <th>Y</th>
      <th>Minterm</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>I<sub>0</sub></td>
      <td><span style="text-decoration: overline;">S</span><sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>0</sub></td>
    </tr>
    <tr>
      <td>0</td>
      <td>1</td>
      <td>I<sub>1</sub></td>
      <td><span style="text-decoration: overline;">S</span><sub>1</sub>S<sub>0</sub>I<sub>1</sub></td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>I<sub>2</sub></td>
      <td>S<sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>2</sub></td>
    </tr>
    <tr>
      <td>1</td>
      <td>1</td>
      <td>I<sub>3</sub></td>
      <td>S<sub>1</sub>S<sub>0</sub>I<sub>3</sub></td>
    </tr>
  </tbody>
</table>
</div>

<figure align="center">
<img src="https://i.postimg.cc/zDSZLHfB/4-2-1-MUX.png">
<figcaption>4 To 1 Multiplexer Circuit Diagram </figcaption>
</figure>

<blockquote>
  Y = <span style="text-decoration: overline;">S</span><sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>0</sub> + <span style="text-decoration: overline;">S</span><sub>1</sub>S<sub>0</sub>I<sub>1</sub> + S<sub>1</sub><span style="text-decoration: overline;">S</span><sub>0</sub>I<sub>2</sub> + S<sub>1</sub>S<sub>0</sub>I<sub>3</sub>
</blockquote>
<br>

*&mdash; Edited by Baibhav Bhattacharya*