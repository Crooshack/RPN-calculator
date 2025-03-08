# Postfix Notation Converter and Evaluator

## Overview
This program reads a set of arithmetic formulas in infix notation, converts them to postfix notation, and evaluates them step by step while displaying the stack content at each operation.

## Input Format
1. An integer `n` representing the number of formulas.
2. `n` formulas, each:
   - Written in infix notation.
   - Containing functions and operators.
   - Ending with a dot (`.`).
   - Tokens separated by whitespace.

### Available Operations
Operations are listed in ascending order of priority:
- **Addition & Subtraction**: `a + b`, `a - b`
- **Multiplication & Integer Division**: `a * b`, `a / b` (integer division rounds down, division by zero is not allowed)
- **Conditional Expression**: `IF(a, b, c)` → Returns `b` if `a > 0`, otherwise `c`
- **Unary Negation**: `N a` → Computes `-a`
- **Minimum & Maximum Functions**:
  - `MIN(a1, a2, ...)` → Returns the smallest argument.
  - `MAX(a1, a2, ...)` → Returns the largest argument.
- **Parentheses**: `( ... )`

## Output Format
For each formula:
1. The equivalent postfix notation.
2. The stack content before executing each operation.
3. The final result.
4. If division by zero occurs, print `ERROR` and move to the next expression.

## Example
### Input:
```
4
MIN ( 100 , MAX ( 1 , 34 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) .
2 + MIN ( 100 , MAX ( 1 , 6 * 5 + 2 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) * 3 .
N 400 + ( 11 - ( 3 * 2 ) ) / 2 + N N 200 .
IF ( ( 6 + 8 ) , ( 4 / 2 ) , MIN ( 8 , 2 , 1 , 0 , 3 ) ) * 2 * 6 / N ( 3 ) .
```

### Output:
```
100  1  34  2  MAX3  80  66  36  35  77  MIN4  50  60  MIN6
MAX3 2 34 1 100
MIN4 77 35 36 66 80 34 100
MIN6 60 50 35 80 34 100
34

2  100  1  6  5  *  2  +  2  MAX3  80  66  36  35  77  MIN4  50  60  MIN6  3  *  +
* 5 6 1 100 2
+ 2 30 1 100 2
MAX3 2 32 1 100 2
MIN4 77 35 36 66 80 32 100 2
MIN6 60 50 35 80 32 100 2
* 3 32 2
+ 96 2
98

400  N  11  3  2  *  -  2  /  +  200  N  N  +
N 400
* 2 3 11 -400
- 6 11 -400
/ 2 5 -400
+ 2 -400
N 200 -398
N -200 -398
+ 200 -398
-198

6  8  +  4  2  /  8  2  1  0  3  MIN5  IF  2  *  6  *  3  N  /
+ 8 6
/ 2 4 14
MIN5 3 0 1 2 8 2 14
IF 0 2 14
* 2 2
* 6 4
N 3 24
/ -3 24
-8
```

## Error Handling
- If a division by zero occurs, the program prints `ERROR` and moves to the next expression.

## Notes
- The program follows standard integer arithmetic rules.
- Functions `MIN` and `MAX` can have multiple parameters.
- Operator precedence and associativity are handled correctly during conversion to postfix notation.
- Parentheses ensure proper evaluation order.

---

### License
This project is open-source and available under the MIT License.