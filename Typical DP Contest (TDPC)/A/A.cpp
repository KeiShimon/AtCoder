#include <iostream>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

using namespace std;

int n, vp[101];
bool dp[10010];
const int max_score = 10000;

int main()
{
	cin >> n;
	REP(i, n) cin >> vp[i];

	dp[0] = 1;

	REP(i, n)
		for (int j = max_score; j - vp[i] >= 0; --j)
			dp[j] |= dp[j - vp[i]];

	int ans = 0;
	REPC(i, max_score)
		ans += dp[i];

	cout << ans << endl;
}
