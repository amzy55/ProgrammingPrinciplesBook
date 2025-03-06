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
	
}