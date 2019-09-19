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
void inline swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void inline swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

vector<vector<int>> g;
int n, m;
vector<pair<int, int>> bridge;
vector<int> articulation;

vector<bool> visited;
vector<int> ord;
vector<int> low;


void init()
{
	cin >> n >> m;

	g.resize(n);

	REP(i, m)
	{
		int a, b; cin >> a >> b; --a; --b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	visited.resize(n, false);
	ord.resize(n, -1);
	low.resize(n, -1);
}

template <class T>
void lowlink(const T v, const T par, int k = 0)
{
	ord[v] = low[v] = k;
	visited[v] = true;

	bool is_articulation = false;
	int cnt = 0;

	for (T adj : g[v])
	{
		if (!visited[adj])
		{
			++cnt;
			lowlink(adj, v, k + 1);
			low[v] = min(low[v], low[adj]);

			is_articulation |= (~par) && (ord[v] <= low[adj]);

			if (ord[v] < low[adj])
				bridge.emplace_back(minmax(v, adj));
		}
		else if (adj != par)
		{
			low[v] = min(low[v], ord[adj]);
		}
	}

	is_articulation |= (par == -1) && (cnt > 1);
	if (is_articulation)
		articulation.PB(v);
}

int main()
{
	init();

	lowlink(0, -1);

	cout << bridge.size() << endl;


}