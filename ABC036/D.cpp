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


typedef pair<ll, ll> P;
vvi g;
vector<P> res;
int n;
vector<bool> visited;


P dfs(int v)
{
	if (visited[v])
		return res[v];
	else
		visited[v] = true;

	ll w = 1, b = 1;

	REP(i, SZ(g[v]))
	{
		if (!visited[g[v][i]])
		{
			P p = dfs(g[v][i]);
			w = w * ((p.first + p.second) % MOD) % MOD;
			b = b * p.first % MOD;
		}
	}

	return res[v] = P(w, b);
}


void init()
{
	cin >> n;
	g.resize(n);
	visited.resize(n, false);
	res.resize(n);

	REP(_i, n - 1)
	{
		int a, b;
		cin >> a >> b; --a; --b;
		g[a].PB(b);
		g[b].PB(a);
	}
}


int main()
{
	init();

	P p = dfs(0);
	ll ans = (p.first + p.second) % MOD;
	cout << ans << endl;
}
