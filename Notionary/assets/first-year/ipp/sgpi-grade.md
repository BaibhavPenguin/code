# IPP &mdash; Grade from SGPA
---
### <u>Title</u>  

Write a program in python to find the grade from given SGPA.

---

### <u>Explanation</u>
The user will enter the **spga** the program should find the grade using **If...Elif...Else Statements**  
**SGPA Between 10.0 &mdash; 9.00** : Grade = O  
**SGPA Between 8.99 &mdash; 8.00** : Grade = A+  
**SGPA Between 7.99 &mdash; 7.00** : Grade = A  
**SGPA Between 6.99 &mdash; 6.00** : Grade = B+    
**SGPA Between 5.99 &mdash; 5.50** : Grade = B  
**SGPA Between 5.49 &mdash; 4.00** : Grade = C  
**SGPA Between 3.99 &mdash; 0.00** : Fail  


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
print("Grade from SGPA - IPP")
sgpa = float(input("Enter your SGPA : "))
if 9.0 <= sgpa <= 10.0:
    print("Your grade is O")
elif 8.0 <= sgpa <= 8.99:
    print("Your grade is A+")
elif 7.0 <= sgpa <= 7.99:
    print("Your grade is A")
elif 6.0 <= sgpa <= 6.99:
    print("Your grade is B+")
elif 5.50 <= sgpa <= 5.99:
    print("Your grade is B")
elif 4.00 <= sgpa <= 5.49:
    print("Your grade is C")
elif 0.00 <= sgpa <= 3.99:
    print("You Failed!")
else:
    print("Invalid SGPA!")
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
