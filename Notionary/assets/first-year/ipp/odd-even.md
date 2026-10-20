# IPP &mdash; Odd or Even
---

### <u>Title</u>  

Write a program in python to find whether the given number is odd or even.

---

### <u>Explanation</u>
The user will enter a number **num** the program should identify whether the number is an odd or an even number using **If...Else Statements**

### <u>Program</u>
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
print("Find whether number is odd or even - IPP")
num = int(input("Enter any number : "))
if num % 2 == 0:
    print(num," is an even number.")
else:
    print(num," is an odd number.")
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
