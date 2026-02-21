# calculator_handing_variables.cpp

**Source:** Programming Principles and Practice Using C++ (3rd Edition) by Bjarne Stroustrup, Chapter 5/6 Example

## Overview
This file implements a simple calculator supporting variables, arithmetic operations (+, -, *, /, %), parentheses, unary operators, and basic error handling. It is adapted from the book's exercises and examples.

## Features
- Variable declaration and assignment (e.g., `let x = 5;`)
- Arithmetic expressions with operator precedence
- Predefined constants: `pi`, `e`
- Print result with `;`, quit with `q`

## Key Components
- **Token & Token_stream:** Handles parsing input into tokens for the calculator.
- **Variable Table:** Stores variable names and values, supports declaration and assignment.
- **Expression Parsing:** Recursive descent parser for expressions, terms, and primaries.
- **Error Handling:** Throws exceptions for invalid input or operations (e.g., divide by zero).

## Usage
Run the program and enter expressions or variable declarations. End each statement with `;` to print the result. Use `q` to quit.

## Example
```
let x = 23.3;
x + 2;
(pi * 2) + x;
```

## Structure
- `main()`: Initializes constants, starts calculator loop
- `calculate()`: Main REPL loop
- `statement()`, `expression()`, `term()`, `primary()`: Parsing functions
- `define_name()`, `is_declared()`: Variable management

---
This code is for educational purposes, following Bjarne Stroustrup's book.