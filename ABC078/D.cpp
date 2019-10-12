#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 1 << 28;

int a_init, b_init, n;
Vi vc;
// dp[acting player][the number of cards remaining when a turn is passed]
int dp[2][2001];

void init()
{
	cin >> n >> a_init >> b_init;

	vc.resize(n);
	REP(i, n) cin >> vc[i];
}

int main()
{
	init();

	for (int i = 1; i < n; ++i)
	{
		int c_other = vc[n - i - 1];
		int res;

		// p0, maximize
		res = abs(vc.back() - c_other);
		for (int j = i - 1; j >= 1; --j)
			chmax(res, dp[1][j]);

		dp[0][i] = res;

		// p1, minimize
		res = abs(vc.back() - c_other);
		for (int j = i - 1; j >= 1; --j)
			chmin(res, dp[0][j]);
		dp[1][i] = res;
	}

	int ans = abs(b_init - vc.back());
	for (int i = n - 1; i >= 1; --i)
		chmax(ans, dp[1][i]);

	cout << ans << endl;
}
