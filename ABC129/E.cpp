#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i > 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class E {
	const int MOD{ 1000000007 };
	string l;
	int n;
	vector<vector<ll>> dp;
public:
	E()
	{
		cin >> l;
		n = SZ(l);
		dp.resize(2, vector<ll>(n + 1, 0));
		dp[0][0] = 1;
	}
	void solve()
	{
		REP(i, n)
		{
			if (l[i] == '0')
			{
				dp[0][i + 1] = dp[0][i];
				dp[1][i + 1] = 3 * dp[1][i] % MOD;
			}
			else
			{
				dp[0][i + 1] = 2 * dp[0][i] % MOD;
				dp[1][i + 1] = (dp[0][i] + 3 * dp[1][i]) % MOD;
			}

		}
		ll ans{ (dp[0][n] + dp[1][n]) % MOD };
		cout << ans << endl;
	}
};


int main()
{
	E solution;
	solution.solve();

	return 0;
}