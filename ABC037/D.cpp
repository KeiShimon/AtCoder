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


const int dx[]{ 1, 0, -1, 0 };
const int dy[]{ 0, 1, 0, -1 };
int h, w;
vvi va;
vvll res;
const ll inf = 1e17;

void init()
{
	cin >> h >> w;
	va.resize(h, vi(w));
	res.resize(h, vll(w, inf));
	REP(i, h)
		REP(j, w)
		cin >> va[i][j];
}

ll dfs(int i, int j)
{
	if (res[i][j] != inf)
		return res[i][j];

	res[i][j] = 1;

	REP(d, 4)
		if (i + dy[d] >= 0 && i + dy[d] < h && j + dx[d] >= 0 && j + dx[d] < w)
			if (va[i][j] < va[i + dy[d]][j + dx[d]])
				res[i][j] = (res[i][j] + dfs(i + dy[d], j + dx[d])) % MOD;

	return res[i][j];
}

int main()
{
	init();

	ll ans = 0;
	
	REP(i, h)
		REP(j, w)
		ans = (ans + dfs(i, j)) % MOD;

	cout << ans << endl;
}
