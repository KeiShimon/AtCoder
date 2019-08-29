#include <iostream>

using namespace std;

class B {
	int N, T;
public:
	void solve()
	{
		int c, t;
		int ans{1001};
		for (int i{ 0 }; i < N; i++)
		{
			cin >> c >> t;
			if (t <= T)
			{
				if (c < ans) ans = c;
			}
		}

		if (ans != 1001)
			cout << ans << endl;
		else
			cout << "TLE" << endl;
	}

	B()
	{
		cin >> N >> T;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}