# Basic Logic Gates
---

## <u>Definition of Logic Gates</u>
**Logic Gates are the fundamental physical building blocks of digital logic.**
Logic Gates operate in Boolean Logic i.e. they take one or more digital inputs and produce
a single output corresponding to the underlying predefined logic rules.

## Types of Logic Gates
There are mainly two types of Logic Gates namely **Basic Logic Gates** and **Universal Logic Gates**, the basic logic gates perform a single logical function while universal gates can be used to create any logic gate.


> **Basic Gates :** AND , OR , NOT  
> **Universal Gates :** NAND , NOR  
> **Special Function Gate :** XOR , XNOR

## Theory, Truth Table, Circuit Symbol and Boolean Expression
---
### <u>AND GATE</U>
The AND is a digital logic gate which only outputs high (1) when all of the inputs are high (1)

<link rel="stylesheet" href="./styles/tables.css" >
<div class="dyntable">
<table>
<tr>
<th> A
<th> B
<th> Y
</tr>

<tr>
<td> 0
<td> 0
<td> 0
</tr>

<tr>
<td> 0
<td> 1
<td> 0
</tr>

<tr>
<td> 1
<td> 0
<td> 0
</tr>

<tr>
<td> 1
<td> 1
<td> 1
</tr>

<caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/htW9dqzV/AND-GATE.png">
</figure>
</div>


> **Boolean Expression : A &middot; B**
---

### <u>OR GATE</U>
The OR GATE is a digital logic gate which outputs high (1) when any one or both inputs are high (1)

<div class="dyntable">
<table>
<tr>
<th> A
<th> B
<th> Y
</tr>

<tr>
<td> 0
<td> 0
<td> 0
</tr>

<tr>
<td> 0
<td> 1
<td> 1
</tr>

<tr>
<td> 1
<td> 0
<td> 1
</tr>

<tr>
<td> 1
<td> 1
<td> 1
</tr>

<caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/kg3xbd6t/OR-GATE.png">
    
</figure>
</div>

> **Boolean Expression : A + B**
---


### <u>NOT GATE</u>
The NOT GATE is a digital logic gate which inverts the state of the input i.e. *If A = 0 then Y = 1 and If A = 1 then Y = 0 where A is the input and Y is the output*

<div class="dyntable">
<table>
<tr>
<th> A

<th> Y
</tr>

<tr>
<td> 0
<td> 1
</tr>

<tr>
<td> 1
<td> 0
</tr>


<caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/VkQjCcrt/NOt-GATE.png">
    
</figure>
</div>

> **Boolean Expression : A&#773; = Y**
---

### <u>NAND GATE</u>
The NAND is a digital logic gate which outputs high (1) if any one of the inputs is low (0). It is an inversion of the AND Gate and can also be formed by attaching a NOT Gate to the output of an AND GATE.

<div class="dyntable">
<table>
<tr>
<th> A
<th> B
<th> Y
</tr>

<tr>
<td> 0
<td> 0
<td> 1
</tr>

<tr>
<td> 0
<td> 1
<td> 1
</tr>

<tr>
<td> 1
<td> 0
<td> 1
</tr>

<tr>
<td> 1
<td> 1
<td> 0
</tr>

<caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/t4QhxHZW/NAND-GATE.png">
    
</figure>
<blockquote><strong>Boolean Expression : <span style="text-decoration:overline;">A &middot; B</span> = Y</strong></blockquote>
</div>>

---

### <u>NOR GATE</u>
The NOR is a digital logic gate which only outputs high (1) if all the inputs are low (0). It is an inversion of the OR Gate and can also be formed by attaching a NOT Gate to the output of an OR GATE.

<div class="dyntable">
<table>
<tr>
<th> A
<th> B
<th> Y
</tr>

<tr>
<td> 0
<td> 0
<td> 1
</tr>

<tr>
<td> 0
<td> 1
<td> 0
</tr>

<tr>
<td> 1
<td> 0
<td> 0
</tr>

<tr>
<td> 1
<td> 1
<td> 0
</tr>

<caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/jS0z7rwN/NOR-GATE.png">
    
</figure>
</div>>
<blockquote><strong>Boolean Expression : <span style="text-decoration:overline;">A + B</span> = Y</strong></blockquote>

---


### <u>XOR GATE</u>
The XOR Gate is a digital logic gate which only outputs high (1) if the inputs are different I.e. when A &ne; B

<div class="dyntable">
<table>
<tr>
<th> A
<th> B
<th> Y
</tr>

<tr>
<td> 0
<td> 0
<td> 0
</tr>

<tr>
<td> 0
<td> 1
<td> 1
</tr>

<tr>
<td> 1
<td> 0
<td> 1
</tr>

<tr>
<td> 1
<td> 1
<td> 0
</tr>

<caption><strong>Truth Table</strong></caption>
</table>
<figure>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/8zQh6VJF/XOR-GATE.png">
    
</figure>

<figure>
    <figcaption><strong>XOR Circuit Diagram</strong> </figcaption>   
    <img src="https://i.postimg.cc/CxBTff2H/XOR-CIRCUIT.png">
</figure>
</div>

> **Boolean Expression : AB&#773; + A&#773;B**  
> **Simplified Expression : A &oplus; B**  

---


### <u>XNOR GATE</U>
The XNOR Gate is a digital logic gate which only outputs high (1) if the inputs are same I.e. when A = B
It is the inversion of an XOR Gate. It is considered as a special function gate.

<div class="dyntable">
<table>
<tr>
<th> A
<th> B
<th> Y
</tr>

<tr>
<td> 0
<td> 0
<td> 1
</tr>

<tr>
<td> 0
<td> 1
<td> 0
</tr>

<tr>
<td> 1
<td> 0
<td> 0
</tr>

<tr>
<td> 1
<td> 1
<td> 1
</tr>

<caption><strong>Truth Table</strong></caption>
</table>
<figure align='center'>
    <figcaption><strong>Circuit Symbol</strong> </figcaption>   
    <img src="https://i.postimg.cc/mgfQHGz1/XNOR-GATE.png">
    
</figure>

<figure>
    <figcaption><strong>XNOR Circuit Diagram</strong> </figcaption>   
    <img src="https://i.postimg.cc/8k7zbsxr/XNOR-CIRCUIT.png">
</figure>
</div>

> **Boolean Expression : A &middot; B + A&#773; &middot; B&#773;**  
> **Simplified Expression : A &odot; B**  

---

> **NOTE:** Special function gates are different from universal gates, we can use AND and OR GATES to construct an XOR GATE but we cannot use an XOR GATE to construct an AND or OR GATE hence, an XOR GATE is a Special Function Gate but is **NOT** an Universal Logic Gate.


*&mdash; Edited by Baibhav Bhattacharya*



