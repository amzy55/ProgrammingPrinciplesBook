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
}