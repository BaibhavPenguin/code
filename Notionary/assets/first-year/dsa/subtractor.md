# Half Subtractor & Full Subtractor

## <u> Definition of a Subtractor </u>
---
A Subtractor is a combinational digital circuit which performs arithmetic subtraction on binary bits and generates difference and borrow as result.

## <u> Half Subtractor </u>
---
A Half Subtractor is a combinational digital logic circuit which performs arithmetic subtraction on two binary bits and generates Difference and Borrow as results.  
It is constructed using an XOR and AND gate, the output at the XOR gate is the **Difference** while the output at the AND gate is the **Borrow**.

<link rel="stylesheet" href="./styles/tables.css" >

<div class="dyntable">
<table>
  <thead>
    <tr>
      <th>A</th>
      <th>B</th>
      <th>Difference</th>
      <th>Borrow</th>
       <th>Minterms</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>A&#773;B&#773;</td>
    </tr>
    <tr>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>A&#773;B</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
       <td>AB&#773;</td>
    </tr>
    <tr>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>AB</td>
    </tr>
  </tbody>
  <caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Diagram</strong> </figcaption>   
    <img src="https://i.postimg.cc/T2r5JwKj/Half-Subtractor.png">  
</figure>
</div>

> **Boolean Expression**  
> **Difference :** A &oplus; B   
> **Borrow :** A&#773;B

## <u> Full Subtractor </u>
---
A Full Subtractor is a combinational digital logic circuit which performs arithmetic subtraction on three binary bits and generates Difference and Borrow as results.  
It is constructed using an XOR, AND and OR gates, the output at the XOR gate is the **Difference** while the output at the OR gate is the **Borrow**.

<blockquote><strong>B<sub>in</sub> is taken as 'C' for convenience and clarity while forming equations. </strong></blockquote> <br>

<div class="dyntable">
<table>
  <thead>
    <tr>
      <th>A</th>
      <th>B</th>
      <th>C</th>
      <th>Difference</th>
      <th>Borrow</th>
      <th>Minterms</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>A&#773;B&#773;C&#773;</td>
    </tr>
    <tr>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>A&#773;B&#773;C</td>
    </tr>
    <tr>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>A&#773;BC&#773;</td>
    </tr>
    <tr>
      <td>0</td>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>A&#773;BC</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>AB&#773;C&#773;</td>
    </tr>
    <tr>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>AB&#773;C</td>
    </tr>
    <tr>
      <td>1</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>ABC&#773;</td>
    </tr>
    <tr>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>1</td>
      <td>ABC</td>
    </tr>
  </tbody>
</table>
<figure>
    <figcaption><strong>Circuit Diagram</strong> </figcaption>   
    <img src="https://i.postimg.cc/66d4f38h/Full-Subtractor.png">  
</figure>
</div>

> **Deriving the boolean expression for Difference :**    
> Difference = A&#773;B&#773;C + A&#773;BC&#773; + AB&#773;C&#773; + ABC  
> &therefore;  A&#773;B&#773;C + ABC + A&#773;BC&#773; + AB&#773;C&#773;  
> &therefore;  C(A&#773;B&#773; + AB) +  C&#773;(A&#773;B + AB&#773;)  
> &therefore;  C(A &odot; B) +  C&#773;(A &oplus; B)  
> Hence,  
> **Difference = A &oplus; B &oplus; C**

> **Deriving the boolean expression for Borrow :**  
> Borrow = A&#773;B&#773;C + A&#773;BC&#773; + A&#773;BC + ABC  
> &therefore; A&#773;B&#773;C + ABC  + A&#773;BC&#773; + A&#773;BC  
> &therefore;  C (A&#773;B&#773; + AB ) + A&#773;B(C + C&#773;)  
> &therefore; C (A &odot; B) + A&#773;B  
> Hence,  
<blockquote><strong>Borrow = C &middot; <span style="text-decoration:overline">A &oplus; B</span> + A&#773;B</strong></blockquote>

*&mdash; Edited by Baibhav Bhattacharya*
