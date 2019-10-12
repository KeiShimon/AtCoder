#include <algorithm>
#include <cmath>
#include <deque>
#include <limits.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 1 << 30;
const int max_n = 30001;

void init();

int dp[max_n];
int vc[max_n];
int n;

int main()
{
	init();

	REP(i, n)
		chmin(*lower_bound(dp, dp + max_n, vc[i]), vc[i]);

	int ans = n - (lower_bound(dp, dp + max_n, inf) - dp);
	cout << ans << endl;

}

void init()
{
	cin >> n;
	REP(i, n) cin >> vc[i];
	REP(i, max_n) dp[i] = inf;
}
