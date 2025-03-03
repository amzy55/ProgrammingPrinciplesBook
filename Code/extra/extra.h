#pragma once
#include <iostream>

namespace extra
{
	void specialCharacters()
	{                                    // C++ | ASCII | Definition
		std::cout << "Hello\nHello\n\n"; // \n  - NL    - new line
		std::cout << "Hello\tHello\n\n"; // \t  - HT    - tab
		std::cout << "Hello\vHello\n\n"; // \v  - VT    - vertical tab (it is supposed to move to the next line without resetting the horizontal position to the beginning. it is not fully supported anymore.)
		std::cout << "Hello\bHello\n\n"; // \b  - BS    - backspace
		std::cout << "Hello\rHello\n\n"; // \r  - CR    - carriage return (return to previous line)
		std::cout << "Hello\fHello\n\n"; // \f  - FF    - form feed (obsolete in modern systems, it was used in printers to force a page break, now it has the same effect as new line)
		std::cout << "Hello\aHello\n\n"; // \a  - BEL   - alert (warning/error bell)
	}
}