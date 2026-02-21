# calculatorv1.cpp

**Source:** Programming Principles and Practice Using C++ (3rd Edition) by Bjarne Stroustrup, Chapter 5/6 Example

## Overview
This file is an earlier or simpler version of the calculator from the book. It demonstrates basic arithmetic expression evaluation using recursive descent parsing.

## Features
- Arithmetic operations: +, -, *, /
- Parentheses for grouping
- Simple error handling

## Key Components
- **Token & Token_stream:** Parses input into tokens
- **Expression Parsing:** Functions for parsing expressions, terms, primaries
- **Error Handling:** Throws exceptions for invalid input

## Usage
Run the program and enter arithmetic expressions. End each statement with `;` to print the result. Use `q` to quit.

## Example
```
2 + 3 * (4 - 1);
```

## Structure
- `main()`: Starts calculator loop
- `calculate()`: Main REPL loop
- `statement()`, `expression()`, `term()`, `primary()`: Parsing functions

---
This code is for educational purposes, following Bjarne Stroustrup's book.