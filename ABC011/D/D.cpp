#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> combProb;
void calcCombProbability(int n)
{
	combProb.resize(n + 1);
	combProb[0].resize(2, 0);
	combProb[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		combProb[i].resize(i + 2, 0);
		combProb[i][0] = combProb[i - 1][0] / 2;
		for (int j = 1; j <= i; ++j)
			combProb[i][j] = (combProb[i - 1][j - 1] + combProb[i - 1][j]) / 2;
	}
}

int n, d, x, y;

int main()
{
	cin >> n >> d >> x >> y;

	if ((x % d) || (y % d))
	{
		cout << 0 << endl;
		return 0;
	}

	x /= d; y /= d;
	x = abs(x); y = abs(y);

	if (x + y > n)
	{
		cout << 0 << endl;
		return 0;
	}

	calcCombProbability(n);

	double ans = 0;
	for (int moveH = x; moveH <= n - y; ++moveH)
	{
		double p = combProb[n][moveH];

		if ((moveH - x) & 1)
			continue;
		int moveHrev = (moveH - x) / 2;
		p *= combProb[moveH][moveHrev];

		int moveV = n - moveH;
		if ((moveV - y) & 1)
			continue;
		int moveVrev = (moveV - y) / 2;
		p *= combProb[moveV][moveVrev];

		ans += p;
	}

	cout << setprecision(12) << ans << endl;
}
