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


#include <bitset>

int n, m;
vvll dp;
vvi g;

void init()
{
	cin >> n >> m;
	g.resize(n);
	dp.resize(1 << n, vll(n + 1, 0LL));
	dp[0][0] = 1;

	REP(i, m)
	{
		int a, b;
		cin >> a >> b; --a; --b;
		g[a].PB(b);
	}
}

void debug()
{
	REP(i, SZ(dp))
	{
		REP(j, SZ(dp[i]))
			cout << dp[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	init();

	REP(x, n)
		REP(mask, 1 << n)
	{
		if (dp[mask][x])
		{
//			cout << endl << "dp[" << bitset<4>(mask) << "][" << x << "] = " << dp[mask][x] << endl;
			REP(rabit, n)
				if (!(mask & (1 << rabit)))
				{
//					cout << "  checking " << rabit << endl;
					if (g[rabit].empty())
					{
//						cout << "    rabit " << rabit << " is OK because no condition" << endl;
						dp[mask | (1 << rabit)][x + 1] += dp[mask][x];
					}
					else
					{
						bool flag = true;
						REP(j, SZ(g[rabit]))
							if (!(mask & (1 << g[rabit][j])))
								flag = false;

						if (flag)
						{
//							cout << "    rabit " << rabit << " is OK because all conditions are filled" << endl;
							dp[mask | (1 << rabit)][x + 1] += dp[mask][x];
						}
						else
							continue;
					}
				}
		}
	}

	//debug();

	cout << dp[(1 << n) - 1][n] << endl;

}
