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


typedef pair<ll, int> P;

int n, m;
vector<vector<P>> g;
vll d; // init INF!!
ll INF;
vector<bool> negative;


void init()
{
	cin >> n >> m;

	g.resize(n);
	d.resize(n);

	INF = 200000000000000;

	REP(i, m)
	{
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].emplace_back(MP(-c, b));
	}
}

bool Bellman_Ford(int src)
{
	REP(i, n)
		d[i] = INF;
	d[src] = 0LL;

	REP(i, n - 1)
		REP(v, n)
		REP(i, SZ(g[v]))
	{
		int adj = g[v][i].second;
		ll c = g[v][i].first;
		chmin(d[adj], d[v] + c);
	}

	REP(v, n)
		REP(i, SZ(g[v]))
	{
		if (d[g[v][i].second] > d[v] + g[v][i].first)
			return true;
	}

	return false;
}

void check()
{
	negative.resize(n, false);

	REP(i, n)
		REP(v, SZ(g))
		REP(i, SZ(g[v]))
	{
		int adj = g[v][i].second;
		ll c = g[v][i].first;
		if (chmin(d[adj], d[v] + c))
			negative[adj] = true;

		if (negative[v])
			negative[adj] = true;
	}

}

// http://drken1215.hatenablog.com/entry/2019/02/16/075900

int main()
{
	init();

	Bellman_Ford(0);
	check();
	
	if (negative[n - 1])
	{
		cout << "inf" << endl;
		return 0;
	}

	cout << -d[n - 1] << endl;

}
