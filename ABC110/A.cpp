#include <iostream>

using namespace std;

class A {
	int a, b, c;
public:
	void solve()
	{
		int m{ a };
		if (m < b) m = b;
		if (m < c) m = c;

		cout << (a + b + c + 9 * m) << endl;
	}

	A()
	{
		cin >> a >> b >> c;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}