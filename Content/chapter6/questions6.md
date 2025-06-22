### 1. What do we mean by “Programming is understanding”?
Programming is a way to express and test understanding of a problem. You can't code it if you don't fully understand it.

### 2. The chapter details the creation of a calculator program. Write a short analysis of what the calculator should be able to do.
The calculator should handle basic arithmetic (+, -, *, /) for floating-point values, parentheses and operator precedence.

### 3. How do you break a problem up into smaller manageable parts?
Start from high level and slowly break it down into smaller parts.

### 4. Why is creating a small, limited version of a program a good idea?
It helps test ideas early, reduce complexity, and catch major issues before scaling up.

### 5. Why is feature creep a bad idea?
Feature creep adds unplanned complexity, increasing bugs and delaying delivery. 

### 6. What are the three main phases of software development?
- Analysis (understand the problem)
- Design (plan solution)
- Implementation (code it and test it)

### 7. What is a “use case”?
A specific scenario that shows how a user interacts with a program.

### 8. What is the purpose of testing?
To verify correctness and catch bugs before deployment.

### 9. According to the outline in the chapter, describe the difference between a Term, an Expression, a Number, and a Primary.
- Expression = Term or Expression +,- Term
- Term = Primary or Term *,/ Primary
- Primary = (Expression) or Number
- Number = floating-point-literal
 
 ### 10. In the chapter, an input was broken down into its component Terms, Expressions, Primaries, and Numbers. Do this for (17+4)/(5–1).
 - 17+4 -> Number+Number -> Primary+Primary -> Term+Term -> Expression+Term -> Expression
 - (17+4) -> (Expression) -> Primary 
 - (5-1) -> *similarly* (Expression) -> Primary
 - (17+4)/(5–1) -> Primary/Primary -> Term -> Expression

  
 ### 11. Why does the program not have a function called number()?
 Numbers are parsed within 'primary()', not as a separate function. The parser handles them contextually.
 
 ### 12. What is a token?
 A token is a meaningful unit of input, such as a number, operator, or parenthesis.
 
 ### 13. What is a grammar? A grammar rule?
 Grammar defines a set of rules, a grammar rule states how elements combine (e.g., Expression = Term + Expression).
 
 ### 14. What is a class? What do we use classes for?
 A class groups related data and functions into a new type. 
 
 ### 15. How can we provide a default value for a member of a class?
 Use member initializers in constructors `MyClass() : x(5) {}`or in-class initialization `int x{ 5 };`.
 
 ### 16. In the expression function, why is the default for the switch-statement to “put back” the token?
 So unrecognized input is returned for processing by another part of the parser.

### 17. What is “look-ahead”?
 Look-ahead checks the next token to decide what to do next without consuming it.
 
 ### 18. What does putback() do and why is it useful?
 `putback()` pushes a token back into the buffer so it can be read again later—helps with look-ahead.
 
 ### 19. Why is the remainder (modulus) operation, %, difficult to implement in the term()?
 `%` only works with integers, so term() must check types or handle it separately.
 
 ### 20. What do we use the two data members of the Token class for?
 One stores the token's kind (like '+') and the other stores its value (like 3.14).
 
 ### 21. Why do we (sometimes) split a class’s members into private and public members?
 To enforce encapsulation and hide implementation details while exposing only necessary functionality.
 
 ### 22. What happens in the Token_stream class when there is a token in the buffer and the get() function is called?
 It returns the buffer and the token stream is set to empty.
 
 ### 23. Why were the ';' and 'q' characters added to the switch-statement in the get() function of the Token_stream class?
 To allow ending input (';') and quitting ('q') during user input handling.
 
 ### 24. When should we start testing our program?
 Start early, test each component as soon as it's written.
 
 ### 25. What is a “user-defined type”? Why would we want one?
 A custom type made by the user, a class. The language cannot have a type for every possible functionality, so we can difine our own for specific use cases.
 
 ### 26. What is the interface to a C++ “user-defined type”?
 Its public functions and members, what users can see and use.
 
 ### 27. Why do we want to rely on libraries of code?
 To reuse tested, efficient code and avoid reinventing solutions to common problems to save time.