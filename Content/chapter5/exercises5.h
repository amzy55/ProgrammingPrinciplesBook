#pragma once
#include <iostream>
#include<string>

using namespace std;

namespace ex5
{
	class BadArea{};

	int area(int l, int w)
	{
		if (l <= 0 || w <= 0) throw BadArea{};
		return l * w;
	}

	int framed_area(int l, int w)
	{
		return area(l - 2, w - 2);
	}

	void try_catch()
	{
		try
		{
			int x = -1;
			int y = 2;
			int z = 4;

			int area1 = area(x, y);
			int area2 = framed_area(1, z);
			int area3 = framed_area(y, z);
			double ratio = area1 / area3;
		}
		catch(BadArea)
		{
			cout << "Oops! bad arguments to area()\n";
		}
	}

	// from std_lib_facilities
	struct Range_error : out_of_range {	// enhanced vector range error reporting
		int index;
		Range_error(int i) :out_of_range("Range error: " + to_string(i)), index(i) {}
	};

	void out_of_range()
	{
		try
		{
			vector<int> v;
			for (int x; cin >> x;)
				v.push_back(x);
			for (int i = 0; i <= v.size(); ++i)
				cout << "v[" << i << "] == " << v.at(i) << '\n'; // the book used the classic v[i] but that does not throw an out_of_range exception, it only does in the modified version of vector from std_lib_facilities
		}
		catch (std::out_of_range)
		{
			cerr << "Oops! Range error\n";
		}
		catch (...)
		{
			cerr << "Exception: something went wrong\n";
		}
	}
}