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

typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int n_a, n_b;
const int max_n = 1000, inf = 1 << 28;
int va[max_n], vb[max_n];
int dp[max_n + 2][max_n + 2];

int main()
{
	cin >> n_a >> n_b;
	REP(i, n_a) cin >> va[i];
	REP(i, n_b) cin >> vb[i];

	RREPC(i, n_a)
		RREPC(j, n_b)
	{
		if (i == n_a && j == n_b)
			continue;

		if (!((i + j) & 1))
		{
			if (i == n_a)
				dp[i][j] = dp[i][j + 1] + vb[j];
			else if (j == n_b)
				dp[i][j] = dp[i + 1][j] + va[i];
			else
			{
				dp[i][j] = dp[i + 1][j] + va[i];
				chmax(dp[i][j], dp[i][j + 1] + vb[j]);
			}
		}
		else
		{
			if (i == n_a)
				dp[i][j] = dp[i][j + 1];
			else if (j == n_b)
				dp[i][j] = dp[i + 1][j];
			else
			{
				dp[i][j] = dp[i + 1][j];
				chmin(dp[i][j], dp[i][j + 1]);
			}
		}
	}

	cout << dp[0][0] << endl;
}
