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

//ll dfs(int a, int b, int c, int d)
//{
//	if (a > SZ(wv[0]) || b > SZ(wv[1]) || c > SZ(wv[2]) || d > SZ(wv[3]))
//		return -LLMAX;
//
//	if (a * w + b * (w + 1) + c * (w + 2) + d * (w + 3) > lim)
//		return -LLMAX;
//
//	ll ret = 0;
//	if (a)
//		ret += memo[0][a - 1];
//	if (b)
//		ret += memo[1][b - 1];
//	if (c)
//		ret += memo[2][c - 1];
//	if (d)
//		ret += memo[3][d - 1];
//
//	chmax(ret, dfs(a + 1, b, c, d));
//	chmax(ret, dfs(a, b + 1, c, d));
//	chmax(ret, dfs(a, b, c + 1, d));
//	chmax(ret, dfs(a, b, c, d + 1));
//
//	return ret;
//}


int n;
ll lim, w;
vvll wv, memo;


void init()
{
	ll v, tmp;

	wv.resize(4);
	memo.resize(4, vll(101, 0LL));

	cin >> n >> lim >> w >> v;
	wv[0].PB(v);

	REP(i, n - 1)
	{
		cin >> tmp >> v;
		wv[tmp - w].PB(v);		
	}

	REP(i, 4)
		sort(ALL(wv[i]), greater<ll>());

	REP(i, 4)
	{
		if (!wv[i].empty())
		{
			REP1C(j, SZ(wv[i]))
				memo[i][j] = memo[i][j - 1] + wv[i][j - 1];
		}
	}

}


int main()
{
	init();

	ll ans = 0;

	REPC(a, SZ(wv[0]))
	{
		REPC(b, SZ(wv[1]))
		{
			REPC(c, SZ(wv[2]))
			{
				REPC(d, SZ(wv[3]))
				{
					if (a * w + b * (w + 1) + c * (w + 2) + d * (w + 3) <= lim)
					{
						ll v = memo[0][a] + memo[1][b] + memo[2][c] + memo[3][d];
						chmax(ans, v);
					}
				}
			}
		}
	}

	cout << ans << endl;
}
