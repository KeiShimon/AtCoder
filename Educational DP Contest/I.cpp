#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const int MOD = 1000000007;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

#include <iomanip>


vector<vector<double>> dp;
int n;

int main()
{
	cin >> n;
	dp.resize(n + 1, vector<double>(n + 1, 0));
	dp[0][0] = 1;

	REP(i, n)
	{
		double p; cin >> p;

		REPC(j, n)
		{
			if (j)
				dp[i + 1][j] += dp[i][j - 1] * p;
			dp[i + 1][j] += dp[i][j] * ((double)1 - p);
		}
	}

	double ans = 0;
	for (int i = n / 2 + 1; i <= n; ++i)
		ans += dp[n][i];
	cout << setprecision(12) << ans << endl;
}
