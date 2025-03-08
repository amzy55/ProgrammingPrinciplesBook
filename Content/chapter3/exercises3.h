#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

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
		std::cout << "\nEnter the age of the recipient (followed by 'enter'):\n";

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
	/*Write a program in C++ that converts from miles to kilometers. 
	Your program should have a reasonable prompt for the user to enter a number
	of miles. Hint: There are 1.609 kilometers to the mile.*/
	void ex2()
	{
		std::cout << "Enter a number that signifies miles to be converted into kilometers.\n";
		double miles;
		std::cin >> miles;
		std::cout << miles << " miles is " << miles * 1.609 << " kilometers.";
	}

	/* Write a program that doesn’t do anything, but declares 
	a number of variables (such as int double = 0;), so that you 
	can see how the compiler reacts.*/
	void ex3()
	{
		//int double = 0;
		//int 2hello = 0;
		//int hello? = 0;
		//int hello-hello = 0;
		int hello$ = 0; // so this is allowed but it's compiler specific so it won't work everywhere as it is not in compliance with the C++ standard
		int _hello = 0; // allowed but not recommended
		int hello__hello = 0; // allowed but not recommended
	}

	/*Write a program that prompts the user to enter two integer values. Store 
	these values in int variables named val1 and val2. Write your program to 
	determine the smaller, larger, sum, difference, product, and ratio of these 
	values and report them to the user.*/
	void ex4()
	{
		std::cout << "Input two integers.\n";
		int a, b;
		std::cin >> a >> b;
		int smaller = a < b ? a : b;
		std::cout << "Smaller: " << smaller << "\n";
		int larger = a > b ? a : b;
		std::cout << "Larger: " << larger << "\n";
		std::cout << "Sum: " << a + b << "\n";
		std::cout << "Difference: " << larger - smaller << "\n";
		std::cout << "Product: " << a * b << "\n";
		if (smaller == 0)
		{
			std::cout << "0";
		}
		else
		{
			std::cout << "Ratio: " << larger / smaller << "\n";
		}
	}

	/*Modify the program above to ask the user to enter floating-point values 
	and store them in double variables. Compare the outputs of the two pro
	grams for some inputs of your choice. Are the results the same? Should 
	they be? What’s the difference?*/
	void ex5()
	{
		std::cout << "Input two floating-point values.\n";
		double a, b;
		std::cin >> a >> b;
		double smaller = a < b ? a : b;
		std::cout << "Smaller: " << smaller << "\n";
		double larger = a > b ? a : b;
		std::cout << "Larger: " << larger << "\n";
		std::cout << "Sum: " << a + b << "\n";
		std::cout << "Difference: " << larger - smaller << "\n";
		std::cout << "Product: " << a * b << "\n";
		if (smaller == 0)
		{
			std::cout << "0";
		}
		else
		{
			std::cout << "Ratio: " << larger / smaller << "\n";
		}
		// If we input whole numbers only the ratio is different (compared to th ex4) because the answer can have a fractional part too.
	}

	/*Write a program that prompts the user to enter three integer values, and 
	then outputs the values in numerical sequence separated by commas. So, 
	if the user enters the values 10 4 6, the output should be 4, 6, 10. If two 
	values are the same, they should just be ordered together. So, the input 
	4 5 4 should give 4, 4, 5.*/
	void ex6()
	{
		std::cout << "Input three integers to be ordered.\n";
		std::vector<int> numbers(3);
		std::cin >> numbers[0] >> numbers[1] >> numbers[2];
		std::sort(numbers.begin(), numbers.end()); // cheating :P
		std::cout << numbers[0] << ", " << numbers[1] << ", " << numbers[2];
	}
}