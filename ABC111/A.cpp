#include <iostream>
#include <sstream>

using namespace std;

class A {
	string s;
public:
	void solve()
	{
		ostringstream oss;

		for (char c : s)
		{
			if (c == '9') oss << '1';
			else oss << '9';
		}

		cout << oss.str() << endl;
	}

	A()
	{
		cin >> s;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}