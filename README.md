# 🧮 APC - Arbitrary Precision Calculator

---

## 📝 Brief Summary

This project is an **Arbitrary Precision Calculator (APC)** implemented in C using **doubly linked lists**.

The calculator performs arithmetic operations on large integers that cannot be handled reliably using standard C integer data types.

The project supports:

Addition → `+`

Subtraction → `-`

Multiplication → `x` / `X`

Division → `/`

The numbers are stored digit-by-digit in a doubly linked list, allowing the program to perform calculations on numbers with a large number of digits.

---

## 📌 Overview

Standard C data types such as `int` and `long` have limited ranges and cannot store very large integers.

For example:

```text
123456789012345678901234567890
```

A number of this size cannot be stored in a normal `int` or `long` variable.

To overcome this limitation, this project stores each digit of the number in a **doubly linked list**.

For example:

```text
12345
```

is stored as:

```text
1 <-> 2 <-> 3 <-> 4 <-> 5
```

Each node stores one digit along with pointers to the previous and next nodes.

The project helped me understand:

-> Arbitrary precision arithmetic

-> Doubly linked lists

-> Dynamic memory allocation

-> Carry and borrow handling

-> Linked-list based arithmetic operations

-> Command-line argument handling

-> Modular programming in C

-> Handling signed numbers

---

## 🎯 Problem Statement

C provides fixed-size integer data types, which limits the size of numbers that can be directly stored and processed.

The objective of this project is to develop a calculator that can perform arithmetic operations on very large integers without depending on the size limitations of standard integer data types.

The project achieves this by:

-> Storing each digit separately in a linked list

-> Performing arithmetic operations digit-by-digit

-> Handling carry and borrow manually

-> Supporting positive and negative operands

-> Producing the final result as a linked list

---

## 📂 Input

The calculator accepts three command-line arguments:

```text
<operand1> <operator> <operand2>
```

Example:

```bash
./apc 12345678901234567890 + 98765432109876543210
```

Supported operators:

```text
+     Addition

-     Subtraction

x / X Multiplication

/     Division
```

The operands can contain:

-> Positive numbers

-> Negative numbers

-> Very large integers

---

## 📁 Project Structure

```text
├── main.c
├── apc.c
├── apc.h
├── add.c
├── sub.c
├── mul.c
├── div.c
└── README.md
```

### 📄 File Description

**main.c**

-> Handles command-line arguments

-> Validates the input

-> Determines the sign of operands

-> Selects the required arithmetic operation

-> Displays the final result

**apc.c**

-> Contains common utility functions

-> Validates operands and operators

-> Creates linked lists from input numbers

-> Inserts nodes

-> Compares numbers

-> Removes leading zeros

-> Prints the result

**apc.h**

-> Contains structure definitions

-> Contains macros

-> Contains function declarations

**add.c**

-> Implements addition of large numbers

-> Handles carry between digits

**sub.c**

-> Implements subtraction of large numbers

-> Handles borrowing between digits

**mul.c**

-> Implements multiplication of large numbers

-> Performs digit-by-digit multiplication

-> Handles partial products and carry

**div.c**

-> Implements division of large numbers

-> Uses repeated subtraction to calculate the quotient

---

## 🛠️ Tools and Technologies Used

**Programming Language**

```text
C
```

 **Operating System**

```text
Linux (Ubuntu)
```

**Compiler**

```text
GCC
```

**Development Tools**

```text
VS Code

Git & GitHub
```

**Concepts Used**

```text
Doubly Linked Lists

Dynamic Memory Allocation

Pointers

Structures

Command-Line Arguments

File Organization

Functions

Modular Programming

Arithmetic Operations

Carry and Borrow

String Handling

Input Validation
```

---

## 🔧 Methods

**➕ Addition**

The addition operation processes both numbers from the **least significant digit**.

Since the numbers are stored in a doubly linked list, the calculation starts from the tail of each list.

Example:

```text
   999
 + 123
 -----
  1122
```

The program:

-> Starts from the last digit

-> Adds corresponding digits

-> Adds the carry

-> Stores the resulting digit

-> Moves towards the most significant digit

-> Inserts the final carry if required

---

**➖ Subtraction**

Subtraction is performed digit-by-digit from right to left.

The program handles borrowing when the digit of the first operand is smaller than the digit of the second operand.

Example:

```text
  1000
-  456
------
   544
```

The program:

-> Starts from the least significant digit

-> Checks whether borrowing is required

-> Calculates the difference

-> Moves to the previous digit

-> Removes unnecessary leading zeros from the result

---

**✖️ Multiplication**

Multiplication is performed using digit-by-digit multiplication.

For example:

```text
    123
  ×  45
  -----
    615
   492
  -----
   5535
```

The program:

-> Multiplies each digit

-> Handles carry

-> Creates partial products

-> Adds zeros according to the digit position

-> Adds the partial products

-> Produces the final result

---

**➗ Division**

Division is implemented using **repeated subtraction**.

The program:

-> Compares the two operands

-> Subtracts the divisor from the dividend

-> Increments the quotient

-> Continues until the remaining value is smaller than the divisor

For example:

```text
20 / 5

20 - 5 = 15
15 - 5 = 10
10 - 5 = 5
 5 - 5 = 0

Quotient = 4
```

---

## 🔢 Doubly Linked List Representation

Each digit is stored inside a node:

```c
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;
```

For example, the number:

```text
987654
```

is represented as:

```text
NULL
  ↓
9 <-> 8 <-> 7 <-> 6 <-> 5 <-> 4
                                      ↓
                                    NULL
```

This allows the program to traverse the number in both directions.

---

## ➕ Handling Signed Numbers

The calculator supports signed operands.

Examples:

```text
-100 + 50
100 + -50
-100 + -50
-100 - 50
100 - -50
```

The program first identifies the sign of each operand and then performs the appropriate addition or subtraction operation.

For multiplication:

```text
Positive × Positive = Positive

Negative × Negative = Positive

Positive × Negative = Negative

Negative × Positive = Negative
```

---

## 🔄 Program Flow

```text
                         START
                           ↓
                Read command-line arguments
                           ↓
                    Validate input
                           ↓
                Check operator & operands
                           ↓
                  Create linked lists
                           ↓
                    Identify operation
                           ↓
          ┌────────────────┼────────────────┐
          ↓                ↓                ↓
       Addition        Subtraction     Multiplication
          ↓                ↓                ↓
       Carry             Borrow       Partial Products
          ↓                ↓                ↓
          └────────────────┼────────────────┘
                           ↓
                       Division
                           ↓
                  Repeated Subtraction
                           ↓
                    Store Result
                           ↓
                    Remove Leading Zeros
                           ↓
                    Display Result
                           ↓
                          END
```

---

## 💡 Key Insights

-> Learned how arbitrary precision arithmetic works

-> Understood how large numbers can be represented using linked lists

-> Implemented arithmetic without using built-in large integer data types

-> Improved understanding of doubly linked lists

-> Practiced dynamic memory allocation using `malloc()` and `free()`

-> Learned how carry and borrow are handled manually

-> Improved pointer manipulation skills

-> Learned command-line argument handling

-> Practiced modular programming by separating operations into different files

-> Improved debugging and problem-solving skills

---

## 📦 Output

**➕ Addition**

```bash
./apc 12345678901234567890 + 98765432109876543210
```

Output:

```text
Result : Head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 0 <- Tail
```

**➖ Subtraction**

```bash
./apc 10000000000000000000 - 123456789
```

The program calculates the difference and displays it using the linked-list representation.

**✖️ Multiplication**

```bash
./apc 123456789 x 987654321
```

The program performs digit-by-digit multiplication and displays the result.

**➗ Division**

```bash
./apc 1000 / 25
```

Output:

```text
Quotient = 40
```

---

## 🚀 How to Run This Project

**Clone Repository**

```bash
git clone https://github.com/shabeena1703/Arbitrary-Precision-Calculator.git.
```

**Navigate to Project Folder**

```bash
cd APC
```

**Compile**

```bash
gcc main.c apc.c add.c sub.c mul.c div.c -o apc
```

**Run Addition**

```bash
./apc 12345678901234567890 + 98765432109876543210
```

**Run Subtraction**

```bash
./apc 10000000000000000000 - 123456789
```

**Run Multiplication**

```bash
./apc 123456789 x 987654321
```
 **Run Division**

```bash
./apc 1000 / 25
```

---

## ⚠️ Input Validation

The program validates:

-> Number of command-line arguments

-> Valid arithmetic operator

-> Valid numeric operands

-> Signed numbers

-> Division by zero

Example:

```bash
./apc 100 / 0
```

Output:

```text
Division by zero not possible
```

Invalid operator:

```bash
./apc 100 % 20
```

Output:

```text
Invalid operator
```

Invalid operand:

```bash
./apc 100 + abc
```

Output:

```text
Invalid operand
```

---

## ⚠️ Challenges Faced

-> Representing very large numbers using linked lists

-> Managing dynamic memory allocation

-> Performing addition with carry

-> Performing subtraction with borrow

-> Implementing multiplication using partial products

-> Implementing division using repeated subtraction

-> Handling positive and negative operands

-> Comparing large numbers stored in linked lists

-> Removing unnecessary leading zeros

-> Managing multiple linked lists during multiplication

-> Handling pointers correctly during insertion and deletion

---

## 🧪 Result and Conclusion

This project successfully implements an **Arbitrary Precision Calculator in C** using **doubly linked lists**.

The calculator performs addition, subtraction, multiplication, and division on large integers without relying on the limitations of standard C integer data types.

The project provided practical experience in data structures, pointers, dynamic memory allocation, linked-list manipulation, arithmetic algorithms, and modular C programming.

---

## 🔮 Future Work

-> Improve division using a more efficient long-division algorithm

-> Add modulus `%` operation

-> Add power operation

-> Add support for decimal/floating-point numbers

-> Improve calculation speed for extremely large numbers

-> Add memory cleanup functions for all result lists

-> Add automated test cases

-> Improve output formatting

-> Build a menu-driven version

-> Develop a graphical user interface

---

## 👤 Author & Contact

**Shaik Shabeena**

Electronics and Communication Engineering

📧 Email: [skshabeena33@gmail.com]

🔗 LinkedIn: https://www.linkedin.com/in/shaik-shabeena-36a7b9332/
