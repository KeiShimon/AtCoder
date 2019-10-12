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
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
const int max_w = 10000;
int n, w;
int dp[10001];

int main()
{
	cin >> n >> w;

	memset(dp, -1, sizeof dp);
	dp[0] = 0;

	REP(_i, n)
	{
		int v_item, w_item;
		cin >> v_item >> w_item;

		REP(i, w)
			if (dp[i] != -1)
				if (i + w_item <= w)
					chmax(dp[i + w_item], dp[i] + v_item);
	}

	int ans = 0;
	REPC(i, w)
		chmax(ans, dp[i]);

	cout << ans << endl;
}