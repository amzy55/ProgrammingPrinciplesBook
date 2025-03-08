
1. ### What is meant by the term prompt?
Instruction that prompt the user to take an action. Example: "Enter your age."


2. ### Which operator do you use to read into a variable?
`>>`

3. ### If you want the user to input an integer value into your program for a variable named number, what are two lines of code you could write to ask the user to do it and to input the value into your program?
```c++
int number;
std::cin >> number;
```

4. ### What is \n called and what purpose does it serve?
new line

5. ### What terminates input into a string?
Any sort of white space like space, tab or enter

6. ### What terminates input into an integer?
Same as string. If non valid characters (so not numbers) are input the value will g=just be zero.

7. ### How would you write the following code as a single line of code?
 ```c++
 cout << "Hello, ";
 cout << first_name;
 cout << "!\n";
 ```
 
 Answer:
 ```c++
 cout << "Hello, " << first_name << "!\n";
 ```

8. ### What is an object?
A region in memory with a type which specifies what kind of information can be placed there.

9. ### What is a literal?
A constant value.

10. ### What kinds of literals are there?
There are literals for all the integrated types:
- **int**
    - **decimal** (ex: 123)
    - **octal** with digits from 0 to 7 - suffix `0` (ex: 0123 in base 8 is 83 in base 10)
    - **hexadecimal** with digits from 0 to 9 and letters from A to F () - suffix `0x` (ex: 0x123 in hex is 291 in decimal; 0x7B in hex = 123 in *
    - **binary** with digits 0 and 1 - suffix `0b` or `0B` (ex: ```0b0000`0000`0111`1011``` is 123 decimal) *note: "`" is used just a visual separator, can be omitted but it makes the number more readable*
- **float** - contains a point (.) and a suffix `d` of `f` (ex: 1.23f) Floating-point-literals have type double unless a suffix indicates otherwise (ex: 1.23 is a double)
- **boolean** literals can be either `true` or `false`
- **character** literals - letters, digits and certain characters (ex: 'a'). There are also special characters preceded by ```\``` like `\n`.
- **string** - a set of characters enclosed in double quotes ("") (ex: "Hello, World!")
- **pointer** - the pointer literal is special in the sense that it can only have one value which is the null pointer - `nullptr`.

11. ### What is a variable?
A named object.

12. ### What are typical sizes for a char, an int, and a double?
char   - 1 byte <br>
int    - 4 bytes<br>
double - 8 bytes<br>

13. ### What measures do we use for the size of small entities in memory, such as `int`s and `string`s?
bytes or bits 

14. ### What is the difference between = and ==?
= assigns a value to a variable while == is a boolean equal to check if two variables contain the same value

15. ### What is a definition?
A statement that defines a variable.

16. ### What is an initialization and how does it differ from an assignment?
Initialization is assigning a value to a variable at its creation, which assignment is done at any point later during its lifetime.

17. ### What is string concatenation and how do you make it work in C++?
Joining two strings together. Example: std::string myString = "hello" + "world"; // myString = "helloworld"

18. ### Which of the following are legal names in C++? If a name is not legal, why not?
- This_little_pig - legal
- latest thing - no because it contains a space
- MiniMineMine - legal but typo prone
- This_1_is fine - no because it contains a space
- the_$12_method - no because $ is not a valid character for the name of a variable in C++
- number - legal
- 2_For_1_special - no because a variable cannot start with a digit
- _this_is_ok - legal but not recommended because internal variables start with an underscore so it might conflict with one of those names
- correct? - no because ? is not a valid character for the name of a variable in C++

19. ### Give five examples of legal names that you shouldn’t use because they are likely to cause confusion.
M1lIi, m00n

20. ### What are some good rules for choosing names?
Descriptive, not too long, unlikely to cause confusion/error

21. ### What is type safety and why is it important?
Making sure an object is used only according to the rules of their type. Using an uninitialized variable is not considered type safe.
Converting a variable in such a way that it creates data loss is not type safe.

22. ### Why can conversion from double to int be a bad thing?
Firstly because double has a fractional part that an int cannot hold, but even if wanted just the whole part, double has the double the size of int (8 bytes compared to 4 bytes)
so if we convert a double larger then the max int then the value will no longer be correct.

23. ### Define a rule to help decide if a conversion from one type to another is safe or unsafe.
```c++
T1 initialValue{};
T2 convertedValue = initialValue;
std::string result = "type safe";
if (convertedValue != initialValue)
{
    result = "not " + result;
}
std::cout << result;
```