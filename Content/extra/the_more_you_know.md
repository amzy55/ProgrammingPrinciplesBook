# The More You Know
*Information that I did not know (or forgot) before starting to read the book.*
 
- Binary integers are represented starting with 0b or 0B (since C++ 14). Example: 0b0010 (2 in base 10).

- Base 8 integers are represented starting with a 0. Example: 0123 = 1 * 8^2^ + 2 * 8 + 3 = 63 in base 10.

- Floating point literals scientific notation: 1.23e3 = 1230.0 (1.23 * 10^3^ ); 1.23e-3 = 0.00123 (1.23 * 10^-3^).

- In `<chrono>`, a clock counts time in number of (clock) **ticks** and reports the current point in time with the call of `now()` 
```c++
 auto t = steady_clock::now();
 // . . . do something . . .
 auto d = steady_clock::now()-t;  // something took d time units
 cout << "something took " << duration_cast<milliseconds>(d).count() << "ms";
```

- A string holds its length in memory along side its content (I always thought when I call `length()` or `size()` on a string it counts the characters, but nope).

- An `int` is typically **4 bytes** (but can very based on implementation) - I always mix up if it is 4 or 8 bytes.

- It is always safe to convert a smaller size type to a bigger size type, like `int` to `double`.
 However, `float` can only hold 6-7 digits accurately (because of its internal structure),
 so if we want to convert a 9 digit `int` to a `float` the resulting value will not be accurate.
 Converting to a smaller type will lead to data loss (truncation or overflow).

- `float` internal structure:

| Sign  | Exponent         | Mantissa                                       |
|---------------------------------------------------------------------------|
| 1 bit | 8 bits           | 23 bits                                        |
| []    | [][][][][][][][] | [][][][][][][][][][][][][][][][][][][][][][][] |

1 + 8 + 23 = 32 -> 4 bytes

Formula to convert to decimal: **(-1)^Sign^ * (1 + Mantissa) * 2^Exponent - 127^**

*Note that the fractional part is transformed to binary in reverse compared to decimals.*
Decimals are repeatedly divided by 2 and store their values from right to left,
while the fractional part is multiplied by 2 until it reaches `1.0` and stores the bits from left to right.

That is actually why floating point errors exist, because some values never reach exactly `1.0`.

Example: `0.1`

0.1 * 2 = 0.2 -> integer value 0 <br>
0.2 * 2 = 0.4 -> integer value 0 <br>
0.4 * 2 = 0.8 -> integer value 0 <br>
0.8 * 2 = 1.6 -> integer value 1 <br>
0.6 * 2 = 1.2 -> integer value 1 <br>
0.2 * 2 = 0.4 -> integer value 0 <br>
0.4 * 2 = 0.8 -> integer value 0 <br>
0.8 * 2 = 1.6 -> integer value 1 <br>
... starts repeating

Binary:   0001100110011001100110011001100110011... (repeats infinitely) <br>
Mantissa: 00011001100110011001100 (23 bits)

So `0.1` is only stored as an approximation.

- Assigning an `int` to a `char` is allowed by the compiler and will not even give a warning, but initializing a `char` with an `int` will give an error.
Even initializing with `=` is allowed, and only `{}` will give an error (universal and uniform initialization).
*This is all with warning level 3. From 4 it does give warnings.*

Example:
```c++

	int a = 1000;
	char b1 = a;  // allowed, no warnings or **errors** (W3)
	char b2{ a }; // error C2397: conversion from 'int' to 'char' requires a narrowing conversion
```
