#include <iostream>
#include <cmath>

using namespace std;


class B {
	int X;

public:
	void solve()
	{
		cin >> X;

		int ans{ 1 }; // 1 is always an answer
		int tmp;
		for (int base{ 2 }; base <= (int)sqrt(X); base++)
		{
			tmp = base * base;

			while (X >= tmp)
			{
				tmp *= base;
			}
			tmp /= base;
			if (tmp > ans) ans = tmp;

		}

		cout << ans << endl;
	}
};


class A {
	int a, b, c, d;

public:
	void solve()
	{
		cin >> a >> b >> c >> d;

		if ((abs(a - c) <= d) || ((abs(b - a) <= d) && (abs(c - b) <= d))) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}