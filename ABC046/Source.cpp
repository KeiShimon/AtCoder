#include <iostream>
#include <string>

using namespace std;

class A {
	int a, b, c, ans{ 1 };

public:
	void solve()
	{
		cin >> a >> b >> c;

		if (a != b)
		{
			ans += 1;
			if (a != c && b != c)
				ans += 1;
		}
		else
		{
			if (a != c)
				ans += 1;
		}

		cout << ans << endl;
	}
};

class B {
	int n;
	int k;
	int ans{ 1 };

public:
	void solve()
	{
		cin >> n >> k;

		for (int i{ 0 }; i < n; i++)
		{
			if (i)
				ans *= k - 1;
			else
				ans = k;
		}

		cout << ans << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}