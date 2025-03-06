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

	void drillLetter()
	{
		std::cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
		std::string firstName;
		std::cin >> firstName;
		std::cout << "Dear " << firstName << ",\n\n";
		std::cout << "How are you? I am fine. I miss you. We haven't talked in so long.\n";

		std::cout << "\nEnter the name of a friend (followed by 'enter'):\n";
		std::string friendName;
		std::cin >> friendName;
		std::cout << "Have you seen " << friendName << " lately?\n";
		std::cout << "\nEnter the sex of the friend - 'm' for male or 'f' for female (followed by 'enter'):\n";

		char friendSex{ 0 };
		std::cin >> friendSex;
		if (friendSex == 'f')
		{
			std::cout << "She died.\n";
		}
		else if (friendSex == 'm')
		{
			std::cout << "He died.\n";
		}
		else
		{
			std::cout << "They died.\n";
		}
		std::cout << "\nEnter the age of the recepient (followed by 'enter'):\n";

		int age{ 0 };
		std::cin >> age;
		if (age <= 0 || age >= 110)
		{
			std::cerr << "error: " << "no kidding!" << '\n';
			exit(1);
		}
		if (age == 17)
		{
			std::cout << "Next year you'll be able to vote!\n";
		}
		else if (age > 70)
		{
			std::cout << "I hope you are enjoying retirement.\n";
		}
		else
		{
			std::cout << "Next year you will be " << age + 1 << ".\n";
		}

		std::cout << "\nEnter you name (followed by 'enter'):\n";
		std::string yourName;
		std::cin >> yourName;
		std::cout << "Yours sincerely,\n" << yourName << ".\n";
	}
}