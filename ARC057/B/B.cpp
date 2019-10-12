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
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

using namespace std;

typedef int64_t ll;
typedef vector<int> Vi;
typedef vector<ll> Vl;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const ll inf = 1LL << 40;
const int max_n = 2000;

int n, k;
Vl va, suma;
ll dp[max_n + 1][max_n + 1];

int main()
{
	cin >> n >> k;
	va.resize(n);
	REP(i, n) cin >> va[i];
	suma.resize(n, 0);
	suma[0] = va[0];
	REP1O(i, n) suma[i] = va[i] + suma[i - 1];

	if (k == suma.back())
	{
		cout << 1 << endl;
		return 0;
	}

	REPC(i, max_n) REPC(j, max_n)
		dp[i][j] = inf;
	dp[0][0] = dp[1][0] = 0;
	dp[1][1] = 1;

	REP1O(i, n)
	{
		REPC(j, i)
		{
			chmin(dp[i + 1][j], dp[i][j]);

			if (suma[i - 1] == dp[i][j])
				continue;

			ll d = dp[i][j] * va[i] / suma[i - 1] + 1;
			chmin(dp[i + 1][j + 1], dp[i][j] + d);

		}
	}

	int ans = 0;
	REPC(j, n)
		if (dp[n][j] <= k)
			chmax(ans,j);
	cout << ans << endl;
}
