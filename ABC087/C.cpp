#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

class C {
	int N;
	int a[2][100];
public:
	void solve()
	{
		int ans[2][101];
		memset(ans, 0, sizeof ans);
		ans[0][0] = a[0][0];

		for (int x{ 0 }; x < N; x++)
		{
			ans[0][x + 1] = ans[0][x] + a[0][x + 1];

			ans[1][x] = ans[0][x] + a[1][x];

			if (x)
			{
				ans[1][x] = max(ans[1][x], ans[1][x - 1] + a[1][x]);
			}
		}
		cout << ans[1][N - 1] << endl;
	}

	C()
	{
		cin >> N;
		for (int i{ 0 }; i < N; i++)
			cin >> a[0][i] ;
		for (int i{ 0 }; i < N; i++)
			cin >> a[1][i] ;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}