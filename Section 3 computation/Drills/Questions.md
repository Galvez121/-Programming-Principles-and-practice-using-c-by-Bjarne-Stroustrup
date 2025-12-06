# 📘 Chapter 3 – Computation  
## Drill Exercises (Prompts Only)

This folder contains my work for the **Drill** section of Chapter 3 from *Programming: Principles and Practice Using C++*.  
Below are the exact prompts for the exercises.  
⚠️ **No solutions are included here.** This README only documents the assignment requirements.

---

## 🔢 Drill Prompts

### **[1]**
Write a program that consists of a `while`-loop that (each time around the loop) reads in two `int`s and then prints them. Exit the program when a terminating `'|'` is entered.

---

### **[2]**
Change the program to write out  
- *the smaller value is:* followed by the smaller of the numbers  
- *the larger value is:* followed by the larger value.

---

### **[3]**
Augment the program so that it writes the line **“the numbers are equal”** only if the two numbers are equal.

---

### **[4]**
Change the program so that it uses `double`s instead of `int`s.

---

### **[5]**
Change the program so that it writes out **“the numbers are almost equal”** after writing out which is the larger and the smaller if the two numbers differ by less than `1.0/100`.

---

### **[6]**
Modify the loop so that it reads **one `double`** each time.  
Define two variables to keep track of the smallest and largest values seen so far.  
Each time through the loop, write out the value entered.  
- If it’s the smallest so far, write **“the smallest so far”**  
- If it’s the largest so far, write **“the largest so far”**  

---

### **[7]**
Add a unit to each `double` entered. Input examples:  
`10cm`, `2.5in`, `5ft`, `3.33m`.  

Accept the four units: `cm`, `m`, `in`, `ft`.  
Assume these conversions:  
- `1m = 100cm`  
- `1in = 2.54cm`  
- `1ft = 12in`

Read the unit into a string.  
Values such as `12 m` (with space) may be considered equivalent to `12m`.

---

### **[8]**
Reject values without units or with **illegal** unit types, such as:  
`y`, `yard`, `meter`, `km`, `gallons`, etc.

---

### **[9]**
Keep track of:  
- the sum of values (converted to meters),  
- the smallest value,  
- the largest value,  
- and the number of values entered.

When the loop ends, print all of the above.  
Note: choose a single unit (meters) for maintaining the sum.

---

### **[10]**
Store **all** values entered (converted to meters) in a `vector`.  
At the end, write out the values.

---

### **[11]**
Before writing out the values from the vector, **sort them** (ascending order).

---

## 📁 Purpose
This README serves as a reference for the problem statements while I track my progress and solutions in this repository.
