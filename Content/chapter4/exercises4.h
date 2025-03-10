#pragma once
#include <iostream>
#include <limits>

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
}
