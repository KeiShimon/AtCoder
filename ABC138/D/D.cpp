#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
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
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<char> Vc;
typedef vector<string> Vs;
typedef vector<bool> Vb;
typedef vector<vector<int>> VVi;
typedef vector<vector<ll>> VVl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> P;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }
inline void YES() { cout << "YES" << endl; }
inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; }
inline void No() { cout << "No" << endl; }

const int inf = 1 << 30;
const ll linf = 1LL << 60;
const int MOD = 1000000007;

vector<vector<int>> g;
Vi op, res;
int n, q;

void init()
{
	cin >> n >> q;
	g.resize(n);

	REP(i,  n -1)
	{
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	op.resize(n, 0);
	REP(_i, q)
	{
		int a, v; cin >> a >> v; --a;
		op[a] += v;
	}

	res.resize(n);
}

void dfs(int v, int par, int val)
{
	//cout << "dfs at " << v << " from " << par << endl;

	val += op[v];
	res[v] = val;

	for (int adj : g[v])
		if (adj != par)
			dfs(adj, v, val);
}

int main()
{
	init();
	dfs(0, -1, 0);

	REP(i, n)
		cout << res[i] << " ";
	cout << endl;
}
