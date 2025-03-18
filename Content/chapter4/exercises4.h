#pragma once
#include <iostream>
#include <limits>
#include <algorithm>
#include <bitset>

using namespace std;

namespace ex4
{
	void drillStep5()
	{
		double a, b;
		while (cin >> a >> b)
		{
			if (a == '|' || b == '|')
			{
				break;
			}
			if (a - b < 1.0 / 100)
			{
				cout << "the numbers are almost equal \n";
			}
			double smaller = a < b ? a : b;
			double larger = a > b ? a : b;
			cout << "the smaller value is: " << smaller << "\n";
			cout << "the larger value is: " << larger << "\n";
		}
	}

	void drillStep6()
	{
		double smallest = numeric_limits<double>::max();
		double largest = numeric_limits<double>::min();
		double x;
		while (cin >> x)
		{
			if (x == '|')
			{
				break;
			}
			cout << x;
			if (x < smallest)
			{
				smallest = x;
				cout << " the smallest value so far.\n";
			}
			if (x > largest)
			{
				largest = x;
				cout << " the largest value so far.\n";
			}
			cout << '\n';
		}
	}

	void drillFinished()
	{
		double smallest = numeric_limits<double>::max();
		double largest = numeric_limits<double>::min();
		double x;
		string unit;
		double sum = 0;
		constexpr double cmInM = 100;
		constexpr double inInft = 12;
		constexpr double cmInIn = 2.54;
		constexpr double InInM = cmInM / cmInIn;
		constexpr double ftInM = InInM / 12;
		int counter = 0;
		vector<double> valuesInMeters;
		while (cin >> x >> unit)
		{
			if (x == '|')
			{
				break;
			}

			bool legal = true;
			double meters = 0;
			if (unit == "cm")
			{
				cout << x << "cm == " << x / cmInM << "m\n";
				meters = x / cmInM;
			}
			else if (unit == "m")
			{
				cout << x << "m == " << x * cmInM << "cm\n";
				meters = x;
			}
			else if (unit == "in")
			{
				cout << x << "in == " << x / inInft << "ft\n";
				meters = x / InInM;
			}
			else if (unit == "ft")
			{
				cout << x << "ft == " << x * inInft << "in\n";
				meters = x / ftInM;
			}
			else
			{
				cout << "I don't know that unit.\n";
				legal = false;
			}
			cout << '\n';

			if (legal == false)
			{
				continue;
			}

			sum += meters;
			valuesInMeters.push_back(meters);
			counter++;
			if (x < smallest)
			{
				smallest = x;
			}
			if (x > largest)
			{
				largest = x;
			}
			cout << '\n';
		}
		sort(valuesInMeters.begin(), valuesInMeters.end());
		cout << "The smallest legal value is " << smallest << '\n';
		cout << "The largest legal value is " << largest << '\n';
		cout << "The count of legal values is " << counter << '\n';
		cout << "The total of the legal values is " << sum << " meters.\n";
		cout << "All the legal values introduced, converted to meters, in order:\n";
		for (double m : valuesInMeters)
		{
			cout << m << ", ";
		}
	}

	/*If we define the median of a sequence as “a number so that exactly as 
	many elements come before it in the sequence as come after it,” fix the 
	program in §4.6.3 so that it always prints out a median. Hint: A median 
	need not be an element of the sequence.*/
	void ex2()
	{
		vector<double> temps; // temperatures
		for (double temp; cin >> temp; )   // read into temp
			temps.push_back(temp); // put temp into vector
		
		//compute mean temperature
		double sum = 0;
		for (double x : temps) sum += x;
		cout << "Average temperature: " << sum / temps.size() << '\n';
		 
		// compute median temperature
		sort(temps.begin(), temps.end()); // sort temperatures
		cout << "Sorted temperatures: ";
		for (double x : temps) 
			cout << x << ' ';
		cout << "\nMedian temperature: ";
		if (temps.size() % 2 == 1)
		{
			cout << temps[temps.size() / 2] << "\n";
		}
		else
		{
			double median = (temps[temps.size() / 2] + temps[temps.size() / 2 - 1]) / 2;
			cout << median << "\n";
		}
	}

	 /*Write a program to play a numbers guessing game. The user thinks of a 
	number between 1 and 100 and your program asks questions to figure 
	out what the number is (e.g., “Is the number you are thinking of less than 
	50?”). Your program should be able to identify the number after asking 
	no more than seven questions. Hint: Use the < and <= operators and the 
	if-else construct.*/
	void ex4()
	{
		cout << "Think of a number between 1 and 100.\nIs the number you are thinking of less than 50?\nAnswer with y or n.\n";
		char answer;
		cin >> answer;
		if (answer == 'y')
		{
			cout << "Is the number you are thinking of less than 25?\n";
			cin >> answer;
			if (answer == 'y')
			{
				cout << "Is the number you are thinking of less than 13?\n";
				cin >> answer;

				if (answer == 'y')
				{
					cout << "Is the number you are thinking of less than 7?\n";
					cin >> answer;

					if (answer == 'y')
					{
						cout << "Is the number you are thinking of less than 4?\n";
						cin >> answer;

						if (answer == 'y')
						{
							cout << "Is the number you are thinking of less than 2?\n";
							cin >> answer;

							if (answer == 'y')
							{
								cout << "Your number is 1.\nThanks for playing!";
							}
							else
							{
								cout << "Is your number 2?\n";
								cin >> answer;

								if (answer == 'y')
								{
									cout << "Your number is 2.\nThanks for playing!";
								}
								else
								{
									cout << "Your number is 3.\nThanks for playing!";
								}
							}
						}
					}
				}
			}
		}
		// etc... (divide and conquer method)
	}

	/*Make a vector holding the ten string values "zero", "one", . . . "nine". 
	Use that in a program that converts a digit to its corresponding 
	spelled-out value; e.g., the input 7 gives the output seven. Have the same 
	program, using the same input loop, convert spelled-out numbers into 
	their digit form; e.g., the input seven gives the output 7.*/
	void ex6()
	{
		vector<string> numbers = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		};

		cout << "Input a number to receive the spelled out version or vice versa:\n";

		string input;
		while (cin >> input)
		{
			bool validInput = false;
			int num = input[0] - '0';
			if (input.size() == 1 && num >= 0 && num <= 9)
			{
				cout << numbers[num] << ' ';
				validInput = true;
			}
			else
			{
				for (int i = 0; i < numbers.size(); i++)
				{
					if (numbers[i] == input)
					{
						cout << i << ' ';
						validInput = true;
					}
				}
			}
			if (validInput == false)
			{
				cout << "Input invalid.\n";
			}
			else
			{
				cout << '\n';
			}
		}
	}

	/*There is an old story that the emperor wanted to thank the inventor of 
	the game of chess and asked the inventor to name his reward. The inven
	tor asked for one grain of rice for the first square, 2 for the second, 4 for 
	the third, and so on, doubling for each of the 64 squares. That may sound 
	modest, but there wasn’t that much rice in the empire! Write a program to 
	calculate how many squares are required to give the inventor at least 1000 
	grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains. 
	You’ll need a loop, of course, and probably an int to keep track of which 
	square you are at, an int to keep the number of grains on the current 
	square, and an int to keep track of the grains on all previous squares. We 
	suggest that you write out the value of all your variables for each iteration 
	of the loop so that you can see what’s going on.*/
	void ex8()
	{
		int x = 1, power = 0;
		cout << "Power: 0 Value: 1\n"; // Hard-coded first value because I am not using pow()
		while (x < 1'000'000'000)
		{
			power++;
			x *= 2;
				cout << "Power: " << power << " Value: " << x << "\n";
		}
	}

	/*13. Create a program to find all the prime numbers between 1 and 100. There 
	is a classic method for doing this, called the “Sieve of Eratosthenes.” If 
	you don’t know that method, get on the web and look it up. Write your 
	program using this method.
	14. Modify the program described in the previous exercise to take an input 
	value max and then find all prime numbers from 1 to max.*/
	void ex14()
	{
		cout << "Input a number to receive a list with all the primes up until the given number (max 10.000).\n";
		int max;
		cin >> max;
		if (max > 10'000 || max < 0) return;
		vector<int> primes;
		bitset<10'001> marks;
		marks[0] = 1;
		marks[1] = 1;

		for (int i = 2; i < max; i++)
		{
			for (int j = i * i; j < max; j += i)
			{
				marks[j] = 1;
			}
		}

		for (int i = 0; i < max; i++)
		{
			if (marks[i] == 0)
			{
				primes.push_back(i);
			}
		}

		cout << "The prime numbers are: ";
		int i = 0;
		for (auto prime : primes)
		{
			cout << prime << " ";
			i++;
		}
		cout << "\n" << i;
	}

	/*The number that appears the most times 
	in a sequence is called the mode. Create a program that finds the mode of 
	a set of positive integers.*/
	void ex16()
	{
		cout << "Enter a sequence of characters to get the mode (the number that appears the most times).\n";
		vector<int> sequence;
		int x;
		while (cin >> x)
		{
			sequence.push_back(x);
		}

		if (sequence.empty()) {
			cout << "No numbers entered.\n";
			return;
		}

		int max_value = *max_element(sequence.begin(), sequence.end());
		vector<int> counters(max_value + 1, 0);
		
		for (int e : sequence)
		{
			counters[e]++;
		}

		int mostTimes = *std::max_element(counters.begin(), counters.end());
		auto it = std::find(counters.begin(), counters.end(), mostTimes);
		int result = std::distance(counters.begin(), it);

		cout << "The mode of the sequence is " << result << "\n";
	}

	/*Write a program to solve quadratic equations. A quadratic equation is of 
	the form ax^2 + bx + c = 0*/
	void ex18()
	{
		cout << "For the quadratic formula ax^2 + bx + c = 0 enter the values for a, b and c and you will get the real solution for x.\n";
		double a, b, c;
		cin >> a >> b >> c;

		double underSqrt = b * b - 4 * a * c;

		if (underSqrt < 0)
		{
			cout << "x does not have real solutions.";
		}
		else if (underSqrt < 0.0000001)
		{
			double solution = -b / (2 * a);
			cout << "x = " << solution;
		}
		else
		{
			double solution1 = (-b + sqrt(underSqrt)) / (2 * a);
			double solution2 = (-b - sqrt(underSqrt)) / (2 * a);
			cout << "x is an element of { " << solution1 << ", " << solution2 << " }";
		}
	}
}
