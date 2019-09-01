#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i > 0; i--)

using namespace std;

class D {
	static const int MAX_BARS = 8;
	static const int MOD = 1000000007;
	int rows, bars, goal;
	int transition[MAX_BARS][MAX_BARS];
public:
	D()
	{
		cin >> rows >> bars >> goal;
		--goal;

		// create transition table
		memset(transition, 0, sizeof transition);
		int dp[2][MAX_BARS];

		REP(from, bars)
		{
			int adj[]{ from, from + 1};
			for (int to : adj)
			{
				if (to >= bars)
					continue;

				memset(dp, 0, sizeof dp);
				dp[0][0] = 1;
				
				if (from == to)
				{
					REP(i, bars - 1)
					{
						dp[0][i + 1] = dp[1][i] + dp[0][i];

						if (i == to || i + 1 == to)
							dp[1][i + 1] = 0;
						else
							dp[1][i + 1] = dp[0][i];
					}
				}
				else
				{
					REP(i, bars - 1)
					{
						if (i + 1 == to)
						{
							dp[0][i + 1] = 0;
							dp[1][i + 1] = dp[0][i];
						}
						else if (i + 1 == from)
						{
							dp[0][i + 1] = dp[0][i] + dp[1][i];
							dp[1][i + 1] = 0;
						}
						else
						{
							dp[0][i + 1] = dp[1][i] + dp[0][i];
							dp[1][i + 1] = dp[0][i];
						}
					}
				}

				transition[from][to] = transition[to][from] = dp[0][bars - 1] + dp[1][bars - 1];
			}
		}
	}
	void solve()
	{
		vector<vector<int64_t>> dp(rows + 1, vector<int64_t>(bars, 0));
		dp[0][0] = 1;

		REP(row, rows)
		{
			REP(bar, bars)
			{
				int adjs[]{ bar - 1, bar, bar + 1 };
				for (int adj : adjs)
				{
					if (adj < 0 || adj >= bars)
						continue;

					dp[row + 1][adj] += (dp[row][bar] * transition[bar][adj]) % MOD;
				}
			}
		}

		cout << dp[rows][goal] % MOD << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}
