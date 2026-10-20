# IPP &mdash; Greater Number
---

### <u>Title</u>  

Write a program in python to find the Greater number out of the two.

---

### <u>Explanation</u>
The user will enter any two numbers **x** and **y**, the program should compare the two numbers using comparison operators and accurately identify whether x greater than y , y greater than x or both the numbers are equal using **If...Else Statements**


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
print("Find the Greater Number - IPP")
x = int(input("Enter any number : "))
y = int(input("Enter any number : "))
if x > y:
    print(x," is greater")
elif x < y:
    print(y," is greater")
else:
    print("Both numbers are equal.")
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
