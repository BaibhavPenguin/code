# IPP &mdash; Sum of Digits
---
### <u>Title</u>  

Write a program in python to find the Sum of Digits of the given number.

---

### <u>Explanation</u>
The user will enter a number and the program should print the sum of individual digits of the number accurately using **while loops**  
Eg &mdash; If Number is 4534, then the program must calculate 4 + 5 + 3 + 4


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
print("Sum of Digits - IPP")
num = int(input("Enter any number : "))
sum = 0
while(num):
    rem = num % 10
    num = num // 10
    sum+= rem
print("The Sum of Digits :",sum)
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
