#include <iostream>

using namespace std;

class B {
	int N, ans{ 100000000 };
public:
	void solve()
	{
		cin >> N;
		int a, count{ 0 };
		for (int i{ 0 }; i < N; i++)
		{
			cin >> a;
			count = 0;
			while (!(a & 1))
			{
				a >>= 1;
				count++;
			}

			if (count < ans) ans = count;
			if (ans == 0) break;
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