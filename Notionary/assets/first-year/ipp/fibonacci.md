# IPP &mdash; Fibonacci Series
---

### <u>Title</u>  

Write a program in python to print the fibonacci series up to n terms.

---

### <u>Explanation</u>
The user will enter the number of terms and the program should print the Fibonacci Series accurately using **for loops**



### <u>Program </u>

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
print("Fibonacci Series - IPP")
terms = int(input("Enter the number of terms : "))
num1 = 0
num2 = 1
temp = 0
for i in range(terms):
    print(num1,end=" ")
    temp = num1 + num2
    num1 = num2
    num2 = temp
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
