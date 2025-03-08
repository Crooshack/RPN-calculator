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

## Further examples:
```
N ( ( MAX ( 0 , 1 ) + N ( 1 ) ) ) . // this is the input expression 

0  1  MAX2  1  N  +  N              // the postfix notation
MAX2 1 0                            // before each calculation print the operator, then the content of the stack
N 1 1                               
+ -1 1
N 0
0                                   // final result
```

```
MIN ( MIN ( IF ( 0 , 8 , 2 ) ) , MAX ( MIN ( 9 ) , 4 + 9 ) , ( IF ( 3 , 9 , 9 ) / MIN ( 7 , 0 , 6 , 2 , 1 ) ) , N ( 3 + 4 ) , 1 * 1 + IF ( 1 , 9 , 2 ) ) .

0  8  2  IF  MIN1  9  MIN1  4  9  +  MAX2  3  9  9  IF  7  0  6  2  1  MIN5  /  3  4  +  N  1  1  *  1  9  2  IF  +  MIN5
IF 2 8 0
MIN1 2                              // note that each MIN and MAX have their own number of arguments
MIN1 9 2
+ 9 4 9 2
MAX2 13 9 2
IF 9 9 3 13 2
MIN5 1 2 6 0 7 9 13 2
/ 0 9 13 2
ERROR                              // note the division by 0
```

```
( MAX ( N ( 2 ) , 3 * 6 , ( 0 * 5 ) , N ( 4 ) , ( 4 - 9 ) ) + MIN ( MIN ( 8 , 0 , 2 , 2 , 0 , 4 ) ) ) .

2  N  3  6  *  0  5  *  4  N  4  9  -  MAX5  8  0  2  2  0  4  MIN6  MIN1  +
N 2
* 6 3 -2
* 5 0 18 -2
N 4 0 18 -2
- 9 4 -4 0 18 -2
MAX5 -5 -4 0 18 -2
MIN6 4 0 2 2 0 8 18
MIN1 0 18
+ 0 18
18
```

```
N IF ( IF ( 8 , 9 , 6 ) , ( 1 * 2 ) , N 4 ) .

8  9  6  IF  1  2  *  4  N  IF  N
IF 6 9 8
* 2 1 9
N 4 2 9
IF -4 2 9
N 2
-2
```

```
( 9 / 7 ) - IF ( 5 , 5 , 7 ) - ( N 6 - IF ( 8 , 6 , 2 ) ) .

9  7  /  5  5  7  IF  -  6  N  8  6  2  IF  -  -
/ 7 9
IF 7 5 5 1
- 5 1
N 6 -4
IF 2 6 8 -6 -4
- 6 -6 -4
- -12 -4
8
```

```
N ( ( ( 0 * 0 ) + MAX ( 0 , 7 , 9 , 3 ) ) ) .

0  0  *  0  7  9  3  MAX4  +  N
* 0 0
MAX4 3 9 7 0 0
+ 9 0
N 9
-9
```

```
IF ( N 4 , IF ( 3 , 7 , 9 ) , N ( 8 ) ) + N ( 5 * 9 ) .

4  N  3  7  9  IF  8  N  IF  5  9  *  N  +
N 4
IF 9 7 3 -4
N 8 7 -4
IF -8 7 -4
* 9 5 -8
N 45 -8
+ -45 -8
-53
```

```
MIN ( 3 - 9 * 2 / 7 , IF ( 2 + 7 , 0 - 6 , 8 + 0 ) , IF ( 6 * 5 , ( 5 / 8 ) , N ( 6 ) ) , MAX ( 4 , 4 , 4 , 1 ) / 7 * 1 , MIN ( MIN ( 7 , 6 , 0 , 0 , 6 ) , ( 0 * 3 ) , ( 6 * 1 ) , ( 8 + 1 ) ) , ( 7 - 5 + N 4 ) ) .

3  9  2  *  7  /  -  2  7  +  0  6  -  8  0  +  IF  6  5  *  5  8  /  6  N  IF  4  4  4  1  MAX4  7  /  1  *  7  6  0  0  6  MIN5  0  3  *  6  1  *  8  1  +  MIN4  7  5  -  4  N  +  MIN6
* 2 9 3
/ 7 18 3
- 2 3
+ 7 2 1
- 6 0 9 1
+ 0 8 -6 9 1
IF 8 -6 9 1
* 5 6 -6 1
/ 8 5 30 -6 1
N 6 0 30 -6 1
IF -6 0 30 -6 1
MAX4 1 4 4 4 0 -6 1
/ 7 4 0 -6 1
* 1 0 0 -6 1
MIN5 6 0 0 6 7 0 0 -6 1
* 3 0 0 0 0 -6 1
* 1 6 0 0 0 0 -6 1
+ 1 8 6 0 0 0 0 -6 1
MIN4 9 6 0 0 0 0 -6 1
- 5 7 0 0 0 -6 1
N 4 2 0 0 0 -6 1
+ -4 2 0 0 0 -6 1
MIN6 -2 0 0 0 -6 1
-6
```

```
N IF ( MIN ( 2 , 5 ) , ( 2 * 1 ) , MIN ( 3 , 7 , 3 , 3 , 7 , 5 ) ) .

2  5  MIN2  2  1  *  3  7  3  3  7  5  MIN6  IF  N
MIN2 5 2
* 1 2 2
MIN6 5 7 3 3 7 3 2 2
IF 3 2 2
N 2
-2
```

```
MAX ( IF ( 8 , 6 , 0 ) , ( 5 + 0 ) , IF ( 0 , 0 , 5 ) , MIN ( 4 ) ) - N 7 * 5 .

8  6  0  IF  5  0  +  0  0  5  IF  4  MIN1  MAX4  7  N  5  *  -
IF 0 6 8
+ 0 5 6
IF 5 0 0 5 6
MIN1 4 5 5 6
MAX4 4 5 5 6
N 7 6
* 5 -7 6
- -35 6
41
```

```
( MAX ( 0 ) + ( 4 - 1 ) ) + ( IF ( 3 , 7 , 3 ) + ( 8 - 7 ) ) .

0  MAX1  4  1  -  +  3  7  3  IF  8  7  -  +  +
MAX1 0
- 1 4 0
+ 3 0
IF 3 7 3 3
- 7 8 7 3
+ 1 7 3
+ 8 3
11
```

```
IF ( ( N ( 7 ) / N ( 6 ) ) , ( 1 + 3 / N 0 ) , ( 2 / 2 ) / MIN ( 1 , 7 ) ) .

7  N  6  N  /  1  3  0  N  /  +  2  2  /  1  7  MIN2  /  IF
N 7
N 6 -7
/ -6 -7
N 0 3 1 1
/ 0 3 1 1
ERROR
```

```
( 2 + 6 + ( 5 / 5 ) * MIN ( IF ( 3 , 8 , 3 ) ) ) .

2  6  +  5  5  /  3  8  3  IF  MIN1  *  +
+ 6 2
/ 5 5 8
IF 3 8 3 1 8
MIN1 8 1 8
* 8 1 8
+ 8 8
16
```

```
N ( ( 0 / 7 ) / 4 + 3 ) .

0  7  /  4  /  3  +  N
/ 7 0
/ 4 0
+ 3 0
N 3
-3
```

```
IF ( ( 5 + 6 / N ( 4 ) ) , MIN ( ( 1 - 7 ) , 0 / 6 , 6 + 4 , 9 / 1 , 0 - 4 , N 1 ) , N ( 2 * 2 ) ) .

5  6  4  N  /  +  1  7  -  0  6  /  6  4  +  9  1  /  0  4  -  1  N  MIN6  2  2  *  N  IF
N 4 6 5
/ -4 6 5
+ -1 5
- 7 1 4
/ 6 0 -6 4
+ 4 6 0 -6 4
/ 1 9 10 0 -6 4
- 4 0 9 10 0 -6 4
N 1 -4 9 10 0 -6 4
MIN6 -1 -4 9 10 0 -6 4
* 2 2 -6 4
N 4 -6 4
IF -4 -6 4
-6
```

```
N ( ( ( 7 + 4 ) + ( 6 / 3 ) ) ) .

7  4  +  6  3  /  +  N
+ 4 7
/ 3 6 11
+ 2 11
N 13
-13
```

```
IF ( IF ( 7 , 9 , 5 ) / IF ( 8 , 2 , 5 ) , MIN ( IF ( 6 , 0 , 8 ) , N 0 , ( 3 / 0 ) ) , ( 8 - 6 / ( 9 - 9 ) ) ) .

7  9  5  IF  8  2  5  IF  /  6  0  8  IF  0  N  3  0  /  MIN3  8  6  9  9  -  /  -  IF
IF 5 9 7
IF 5 2 8 9
/ 2 9
IF 8 0 6 4
N 0 0 4
/ 0 3 0 0 4
ERROR
```

```
( 5 - 4 ) / N 4 / N ( 0 + 9 ) .

5  4  -  4  N  /  0  9  +  N  /
- 4 5
N 4 1
/ -4 1
+ 9 0 0
N 9 0
/ -9 0
0
```

```
N ( MIN ( 1 , 1 , 6 , 1 , 7 ) + N ( 8 ) ) .

1  1  6  1  7  MIN5  8  N  +  N
MIN5 7 1 6 1 1
N 8 1
+ -8 1
N -7
7
```

## Author of most of the content in this file: 
_- Robert Ostrowski from Gdańsk Tech_
