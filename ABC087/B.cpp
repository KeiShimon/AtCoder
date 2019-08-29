#include <iostream>

using namespace std;

class B {
	int a, b, c, x;
public:
	void solve()
	{
		int ans{ 0 };
		for (int i{ 0 }; i <= a; i++)
		{
			for (int j{ 0 }; j <= b; j++)
			{
				for (int k{ 0 }; k <= c; k++)
				{
					if (500 * i + 100 * j + 50 * k == x) ans++;
				}
			}
		}
		cout << ans << endl;
	}

	B() { cin >> a >> b >> c >> x; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}