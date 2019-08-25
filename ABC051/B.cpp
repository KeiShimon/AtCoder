#include <iostream>

using namespace std;

class B {
	int K, S, ans{ 0 };
public:
	void solve()
	{
		cin >> K >> S;

		int x, y, z, rem;

		for (x = 0; x <= S / 3 && x <= K; x++)
		{
			rem = S - x;
			for (y = x; y <= rem / 2 && y <= K; y++)
			{
				z = rem - y;
				if (z > K) continue;

				if (x != y)
				{
					if (y != z) ans += 6;
					else ans += 3;
				}
				else
				{
					if (y != z) ans += 3;
					else ans += 1;
				}
			}
		}
		cout << ans << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}