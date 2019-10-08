#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)

using namespace std;

typedef int64_t ll;
typedef vector<int> Vi;
typedef vector<vector<int>> VVi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return 1; } return 0; }

int n, m;
ll dp[101][101][101];
VVi seekers;

int main()
{
	cin >> n >> m;

	REP(_i, n)
	{
		int a, b, c; ll w;
		cin >> a >> b >> c >> w;

		chmax(dp[a][b][c], w);
	}

	seekers.resize(m, Vi(3));
	REP(i, m)
		cin >> seekers[i][0] >> seekers[i][1] >> seekers[i][2];

	REPC(i, 100)
		REPC(j, 100)
		REPC(k, 100)
	{
		if (i > 0)
			chmax(dp[i][j][k], dp[i - 1][j][k]);
		if (j > 0)
			chmax(dp[i][j][k], dp[i][j - 1][k]);
		if (k > 0)
			chmax(dp[i][j][k], dp[i][j][k - 1]);
	}

	REP(i, m)
	{
		cout << dp[seekers[i][0]][seekers[i][1]][seekers[i][2]] << endl;
	}
}
