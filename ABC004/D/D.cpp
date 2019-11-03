#include <cmath>
#include <iostream>
#include <string.h>

using namespace std;

template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const int inf = 1 << 28;
const int MAX_J = 2005;
int dp[902][MAX_J];
int R, G, B, N;

// min cost for placing n stones for [x, max_j)
int recursiveDPSolver(int n, int x)
{
	if (!n)
		return 0;

	if (MAX_J - x < n) return inf;

	int ret;
	if ((ret = dp[n][x]) != -1)
		return ret;

	int c;
	if (N - n + 1 <= R)
		c = abs(x - 900);
	else if (N - n + 1 <= R + G)
		c = abs(x - 1000);
	else
		c = abs(x - 1100);

	ret = c + recursiveDPSolver(n - 1, x + 1);
	if (x + 1 < MAX_J)
		chmin(ret, recursiveDPSolver(n, x + 1));

	dp[n][x] = ret;
	return ret;
}

int main()
{
	cin >> R >> G >> B;  N = R + G + B;
	memset(dp, -1, sizeof dp);

	cout << recursiveDPSolver(N, 0) << endl;
}
