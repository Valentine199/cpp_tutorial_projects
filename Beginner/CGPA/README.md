## CGPA calculator

Comulative Grade Point Average calculator is a basic project written in c++ 

### Tech stack
Console application 
- C++ programming language
- Data Structures
- Basic Searching & Sorting algorithms
- Basic Arithmetic Operations and formulas
- File Handling ( I/O Streams )

### Definitions
**GPA**: Grade point avarage: Measurement of academic sucess. 
$$GPA = \frac{\sum_{i=1}^{n}grade_n * credit_n}{\sum_{i=1}^{n}credit_n}$$
total grade points / total number of credits
grade points can range from 1-5 
number of credits is a positive integer. 

**CGPA**: The avarage of the GPA over multiple semesters
$$\frac{1}{n} * \sum_{i=1}^{n}{GPA_i}$$

---
### Use Case
Students input their student id. This way get's identified. 
If the student is not present it get's added

A more robust user handling would be better. With password handling too. For now this is out of the scope. 

The student can have 2 options.

---
'Check statistics' or 'add semester results'

Check statistics: gets a list of semesters each one's GPA noted.
After that shows total credit earned 

in here with 'q' you can return or by selecting the right semester get more details

more details show -> each class taken, their credits, your final result, all students avarage 

The GPA is shown at the bottom.
Show all attempted and achieved credits

'q' returns

----

If you add semester you first have to input how many classes you had. 
Then for each you have to give the name, credit and final grade

After you finished with all you return to the main page.

---
The state of the School with each student and their semesters is saved on:
- Exit 
- When a student adds a semester

This state is stored in a JSON format
The state is loaded at the start of the program and used.

---

## Models
**Student:**
StudentId: str,
Semesters: Array[Array[picked_class]]

**picked_class**:
Name: str,
Credit: int
FinalGrade: int

**School**:
Students: Array[Student]

----
### 2025.11.29. Modifications
Separate display and logic more []
Use pragma once []

