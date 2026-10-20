# IPP &mdash; Simple Interest  
---
### <u>Title</u>  

Write a program in python to find Simple Interest

---

### <u>Explanation</u>
To find the simple interest we will use the formula **SI = (principal amount x rate of interest x tenure) &divide; 100** 

We have to gather Principal Amount, Rate of Interest and Tenure from the user and calculate the Simple Interest and print it. 


<link rel="stylesheet" href="./styles/python.css">
<div class="code-sandbox-wrapper">
  <div class="py-status-badge">
    <span class="py-status-dot"></span>
    <span class="py-status-text">Waiting</span>
  </div>

  <div class="code-island">
    <div class="code-island-header">
      <div class="code-header-left">
        <span class="code-island-title">Python Sandbox</span>
      </div>
      <button class="code-run-btn" onclick="runPythonCode(this)">▶ Run</button>
    </div>
    <div class="code-island-body">
      <div class="code-source">
        <div class="code-gutter">1</div>
        <textarea readonly
          spellcheck="false" 
          placeholder="Write Python code here..." 
          oninput="updateCodeGutter(this)" 
          onscroll="syncCodeGutterScroll(this)"
        >print("Limitless Editor - Roll Number 00")
print("Simple Interest - IPP")
p = float(input("Enter the principal amount : "))
r = float(input("Enter the rate of interest : "))
t = int(input("Enter the tenure : "))
si = (p * r * t) / 100
print("Simple Interest : " , si)
        </textarea>
      </div>
      <div class="code-term">
        <pre class="py-output"></pre>
      </div>
    </div>
  </div>
</div>


Replace the first print statement with your own name and roll number.  
*&mdash; Edited by Baibhav Bhattacharya*
