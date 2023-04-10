# Expression Solver
This expression solver is capable of solving an input expression with the following operands +,-,*,/,^ which can be grouped by paranthesis and seperated by tabs and spaces. If an input file is given it is read, and new lines are treated as new expressions, else the program can get input from stdin.

**Example:** <br>
Input
```
5*4*5
89/74/(9+23*(3+2.5))
(57+9)/(23+8)
```

Output
```
100.000000
0.008876
2.129032
```

Error handling is also iplemented for unmatched paranthesis and invalid operator,operand counts.

