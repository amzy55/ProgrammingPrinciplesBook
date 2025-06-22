 1. ### Name four major types of errors and briefly define each one.
 - Compile-time errors: Errors found by the compiler. We can further classify compile-time errors based on which language rules they violate, for example: 
    - Syntax errors
    - Type errors
- Link-time errors: Errors found by the linker when it is trying to combine object files into an executable program.
- Run-time errors: Errors found by checks in a running program. We can further classify run-time errors as
    - Errors detected by the computer (hardware and/or operating system)
    - Errors detected by a library (e.g., the standard library)
    - Errors detected by user code
- Logic errors: Errors found by the programmer looking for the causes of erroneous results.

 2. ### What kinds of errors can we ignore in student programs?
 Trivial errors that don�t interfere with learning goals, such as minor formatting issues or style warnings.

 3. ### What guarantees should every completed project offer?
 A completed project should be correct, robust (handles errors), maintainable, and well-documented.

 4. ### List three approaches we can take to eliminate errors in programs and produce acceptable software.
 - Use pre-conditions for input to ensure the data that is being fed to program is valid.
 - Use post-conditions to check the output is correct or at least plausible.
 - Comment your code well to help with potential logical errors.

 5. ### Why do we hate debugging?
  Because it�s time-consuming and frustrating.

 6. ### What is a syntax error? Give five examples.
  Syntax errors violate the grammar of the language. Examples:
- Missing semicolon.
- Unmatched braces.
- Misspelled keywords.
- Wrong function declaration.
- Incorrect use of operators.

 7. ### What is a type error? Give five examples.
  Type errors involve incorrect data types. Examples:
- Adding an int to a string.
- Assigning a double to a char.
- Returning the wrong type.
- Passing wrong type to a function.
- Comparing incompatible types.

 8. ### What is a linker error? Give three examples.
 Linker errors occur when combining object files. Examples:
- Undefined reference to function.
- Multiple symbol definitions.
- Missing object file during linking.

 9. ### What is a logic error? Give three examples.
 Logic errors are mistakes in the algorithm. Examples:
- Wrong loop condition.
- Incorrect formula.
- Misplaced return statement.
 
 10. ### List four potential sources of program errors discussed in the text.
 - Complexity.
- Programmer misunderstanding.
- Poor specifications.
- Incomplete testing.
 
 11. ### How do you know if a result is plausible? What techniques do you have to answer such questions?
 Use approximate reasoning, known test values, or comparison to other sources.

 12. ### Compare and contrast having the caller of a function handle a run-time error vs. the called function�s handling the run-time error.
- Caller handling: more flexible, lets the caller decide how to respond, but can make error checking unnecessarily verbose, as well as potentially not making it clear that the function can return wrong results.
- Called function handling: immediate, can simplify code and the caller has a guarantee that the results they're getting are adequate, but it's less flexible, because a caller may want to have different behaviors depending on the error.

Bottom line is that it depends, but the good practice is to handle the errors inside the function, unless there is a specific reason not to.
 
 13. ### Why is using exceptions a better idea than returning an �error value�?
 Because error values can be ignored or misused. Exceptions separate error handling from normal code and enforce handling.
 
 14. ### How do you test if an input operation succeeded?
 Use `if (cin)` or `if (cin.fail())`. Check stream state after input operation.
 
 15. ### Describe the process of how exceptions are thrown and caught. 
 - Use throw to signal an error.
- Surround risky code with try.
- Handle exceptions with catch.

16. ### Why, with a vector called v, is v[v.size()] a range error? What would be the result of calling this?
 `v[v.size()]` accesses one past the last valid index. This is a range error and may crash or return garbage.
 
 17. ### Define pre-condition and post-condition; give an example (that is not the area() function from this chapter), preferably a computation that requires a loop.
 Pre-condition: what must be true before function (e.g., input > 0).
Post-condition: what will be true after (e.g., sorted array). Example: summing positive values in a loop.
 
 18. ### When would you not test a pre-condition?
 When it's guaranteed by design or system constraints (e.g., internal helper functions).
 
 19. ### When would you not test a post-condition?
 When verifying post-condition is redundant or expensive, and correctness is ensured through other means.
 
 21. ### Why does commenting help when debugging?
 Comments clarify intent, helping to spot mismatches between what code does and what it should do.
 
 22. ### How does testing differ from debugging?
 Testing checks for bugs, while debugging finds and fixes them.