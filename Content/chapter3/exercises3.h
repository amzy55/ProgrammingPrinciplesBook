#pragma once
#include <iostream>

namespace ex3
{
	void findRepeatedWords()
	{
		int counter{};
		std::string current;
		std::string previous = " ";
		while (std::cin >> current)
		{
			counter++;

			if (current == previous)
			{
				std::cout << "The word \"" << current << "\" was repeated at position " << counter << ".\n";
			}

			previous = current;
		}
	}

	void intToCharDoesNotGiveWarning()
	{
		int a = 20000;
		char c = a; // try to squeeze a large int into a small char
		int b = c;

		if (a != b)
		{
			std::cout << "Oops!: " << a << " != " << b << '\n';
		}
		else
		{
			std::cout << "Wow! We have large characters!\n";
		}
	}

	void unsafeConversions()
	{
		double d = 0;
		while (std::cin >> d) 
		{
			int i = static_cast<int>(d);              // try to squeeze a double into an int
			char c = i;                               // try to squeeze an int into a char
			int ic = c;                               // get the integer value of the character

			std::cout << "d == "     << d             // the original double
			          << " | i == "  << i             // converted to int
			          << " | ic == " << ic            // int value of char
			          << " | char("  << c << ")\n\n"; // the char
		}
	}	
}