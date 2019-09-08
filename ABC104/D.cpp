#include <iostream>
#include <string>
#include <vector>

#define SZ(x) ((int)(x).size())

typedef int64_t int64;
typedef int64_t ll;

using namespace std;


class D {
	string s;
	const int MOD{ 1000000007 };

	inline ll summod(ll a, ll b) { return (a + b) % MOD; }

public:
	D()
	{
		cin >> s;
	}

	void solve()
	{
		vector<vector<ll>> dp(3, vector<ll>(SZ(s) + 1, 0));
		ll tot{ 1 };

		for (int i{ 1 }; i <= SZ(s); i++)
		{
			switch (s[i - 1])
			{
			case 'A' :
				dp[0][i] = summod(tot, dp[0][i - 1]);
				dp[1][i] = dp[1][i - 1];
				dp[2][i] = dp[2][i - 1];
				break;

			case 'B':
				dp[0][i] = dp[0][i - 1];
				dp[1][i] = summod(dp[0][i - 1], dp[1][i - 1]);
				dp[2][i] = dp[2][i - 1];
				break;

			case 'C':
				dp[0][i] = dp[0][i - 1];
				dp[1][i] = dp[1][i - 1];
				dp[2][i] = summod(dp[1][i - 1], dp[2][i - 1]);
				break;

			default:
				dp[0][i] = summod(tot, dp[0][i - 1] * 3);
				dp[1][i] = summod(dp[0][i - 1], dp[1][i - 1] * 3);
				dp[2][i] = summod(dp[1][i - 1], dp[2][i - 1] * 3);
				tot = tot * 3 % MOD;
				break;
			}
		}

		cout << dp[2][SZ(s)] << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}