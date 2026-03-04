# -Programming-Principles-and-practice-using-c++-by-Bjarne-Stroustrup
I wanted to have my solutions for the Exercises from the book " Programming Principles and practice using c++" by Bjarne Stroustrup. 

I will share my code little by little as I progress through the book.

# Ch 5 and 6
I have finished chapters 5 and 6 so far (02/27/2026).In chapter 5, I learned how a program is built from grammar and how it is translated into functions, tokenization, and error handling.Then, chapter 6 talks more about completing the program; things like cleaning up the code and how to make the code extensible and maintainable. 

Many concepts were introduced in these two chapters, but instead of focusing on why it works, I think this part of the book is designed to teach the reader more about the software engineering part.

# Ch 7

Most names have to be local - avoid using the global variables in a large program.

## Rules
1. Use pass-by-value to pass very small objects
2. Use pass-by-const-reference to pass large objects that you do not need to modify.
3. Return a result rather than modifying an object through a reference argument
4. Use pass-by-reference only when you have to.
