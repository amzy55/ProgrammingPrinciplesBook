1. ### What is a computation?
Takes some input and produces some output.
(I thought it was a set of instructions to be executed)
 
2. ### What do we mean by inputs and outputs to a computation? Give examples.
Data that goes into the computation and data that comes out as a result. Examples: variable values, file contents, pixels on a screen as output, input devices like keyboard or mouse for input.
 
3. ### What are the three requirements a programmer should keep in mind when expressing computations?
Correct, simple, efficient - importance in that order (most of the times)
 
4. ### What does an expression do?
An expression computes a value using operations. Literals are the simplest forms or expressions (10, "Hello") because they compute to their own value. It might sound redundant but an expression is anything that evaluates to a value, so a literal evaluates to them-self.
 
5. ### What is the difference between a statement and an expression, as described in this chapter?
A statement is an instruction for the compiler. A statement can have expressions, but not all expressions are statements. For example `int x = 10;` is an expression statement. There are other types of statements like if-statements.
 
6. ### What is an lvalue? List the operators that require an lvalue. Why do these operators, and not the others, require an lvalue?
An lvalue can only be on the left side of an operation (like `x = 10;`). It can be assigned a new value compared to rvalues (like 10, "Hi").
Operations that require an lvalue: constructing or assigning an object - '=', `{}`, '()'
 
7. ### What is a constant expression?
An expression that has a constant value for the duration of the program. Example: `const int myConstant = x * y; // x * y do not have to be known at compile time`
 
8. ### What is a literal?
An expression that evaluates to itself and cannot have another value.
 
9. ### What is a symbolic constant and why do we use them?
A constant expression that ha sits value known at compile time. Example: `constexpr int CmInM = 100;`
 
10. ### What is a magic constant? Give examples.
A value that is not a constant expression and instead uses the number directly. Like instead of using `constexpr double pi = 3.14;` we just use `3.14` in our code.
 
11. ### What are some operators that we can use for integers and floating-point values?
`+, -, *, /, =, >, <, ==, !=, &&, ||`
 
12. ### What operators can be used on integers but not on floating-point numbers?
`%`
 
13. ### What are some operators that can be used for strings?
`+, =, ==, <, >`
 
14. ### When would a programmer prefer a switch-statement to an if-statement?
When there are multiple options a variable can take and we want different behavior based on the different cases, instead doing multiple if else blocks.
 
15. ### What are some common problems with switch-statements?
Case checking only works with integer constant expression. The programmer can often forget to call `break;` in a case, or forgets to add a 'default;` case.
 
16. ### What is the function of each part of the header line in a for-loop, and in what sequence are they executed?
 
 
17. ### When should the for-loop be used and when should the while-loop be used?
 
 
18. ### How do you print the numeric value of a char?
 
 
19. ### Describe what the line char foo(int x) means in a function definition.
 
 
20. ### When should you define a separate function for part of a program? List reasons.
 
 
21. ### What can you do to an int that you cannot do to a string?
 
 
22. ### What can you do to a string that you cannot do to an int?
 
 
23. ### What is the index of the third element of a vector?
 
 
24. ### How do you write a for-loop that prints every element of a vector?
 
 
25. ### What does vector<char> alphabet(26); do?
 
 
26. ### Describe what push_back() does to a vector.
 
 
27. ### What does vector’s member size() do?
 
 
28. ### What makes vector so popular/useful?
 
 
29. ### How do you sort the elements of a vector?
