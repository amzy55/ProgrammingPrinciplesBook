#pragma once
#include <iostream>
#include <string>
#include "std_lib_facilities.h"

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

	bool drill()
	{
		try {
			//1. Cout << "Success!\n";
			//cout << "Success!\n";
			
			//2. cout << "Success!\n;
			//cout << "Success!\n";
			
			//3. cout << "Success" << !\n"
			//cout << "Success" << "\n";

			//4. cout << success << '\n';
			//cout << "success" << '\n';
			
			//5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
			//int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
		
			//6. vector<int> v(10); v(5) = 7; if (v(5) != 7) cout << "Success!\n";
			//vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";

			//7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
			//bool cond{ true }; if (cond) cout << "Success!\n"; else cout << "Fail!\n";

			//8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
			//bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
			
			//9. string s = "ape"; boo c = "fool" < s; if (c) cout << "Success!\n";
			string s = "ape"; bool c = "fool" > s; if (c) cout << "Success!\n";
			
			//10. string s = "ape"; if (s == "fool") cout << "Success!\n";
			//11. string s = "ape"; if (s == "fool") cout < "Success!\n";
			//12. string s = "ape"; if (s + "fool") cout < "Success!\n";
			//13. vector<char> v(5); for (int i = 0; 0 < v.size(); ++i); cout << "Success!\n";
			//14. vector<char> v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
			//15. string s = "Success!\n"; for (int i = 0; i < 6; ++i) cout << s[i];
			//16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
			//17. int x = 2000; char c = x; if (c == 2000) cout << "Success!\n";
			//18. string s = "Success!\n"; for (int i = 0; i < 10; ++i) cout << s[i];
			//19. vector v(5); for (int i = 0; i <= v.size(); ++i); cout << "Success!\n";
			//20. int i = 0; int j = 9; while (i < 10) ++j; if (j < i) cout << "Success!\n";
			//21. int x = 2; double d = 5 / (x–2); if (d == 2 * x + 0.5) cout << "Success!\n";
			//22. string<char> s = "Success!\n"; for (int i = 0; i <= 10; ++i) cout << s[i];
			//23. int i = 0; while (i < 10) ++j; if (j < i) cout << "Success!\n";
			//24. int x = 4; double d = 5 / (x–2); if (d = 2 * x + 0.5) cout << "Success!\n";
			//25. cin << "Success!\n";
			return true;
		}
		catch (exception& e) {
			cerr << "error: " << e.what() << '\n';
			keep_window_open();
			return false;
		}
		catch (...) {
			cerr << "Oops: unknown exception!\n";
			keep_window_open();
			return false;
		}
	}
}