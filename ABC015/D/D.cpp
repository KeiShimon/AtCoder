#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

using namespace std;

typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

void init();

int w, n, k;
Vi vw, vv;
int dp[51][10001];

int main()
{
	init();

	REP(item, n)
		RREP(i, k)
		RREPC(j, w)
		if (dp[i][j] != -1)
		{
			chmax(dp[i + 1][j], dp[i][j]);
			if (j + vw[item] <= w)
				chmax(dp[i + 1][j + vw[item]], dp[i][j] + vv[item]);
		}

	int ans = 0;
	REP(j, 10001)
		chmax(ans, dp[k][j]);
	cout << ans << endl;
}

void init()
{
	cin >> w >> n >> k;
	vv.resize(n);
	vw.resize(n);

	REP(i, n) cin >> vw[i] >> vv[i];

	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
}