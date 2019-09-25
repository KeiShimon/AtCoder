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

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }



int main()
{
	string s, t;
	cin >> s >> t;
	const int ns = SZ(s), nt = SZ(t);

	vvi dp(ns + 1, vi(nt + 1, 0));

	REP(i, ns)
		REP(j, nt)
	{
		if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
		chmax(dp[i + 1][j + 1], dp[i][j + 1]);
		chmax(dp[i + 1][j + 1], dp[i + 1][j]);
	}

	int i = ns, j = nt;
	string res = "";
	while (i > 0 && j > 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			--i;
		else if (dp[i][j] == dp[i][j - 1])
			--j;
		else // if (dp[i][j] == dp[i - 1][j - 1])
		{
			--i; --j; res.PB(s[i]);
		}
	}

	reverse(ALL(res));
	cout << res << endl;
}
