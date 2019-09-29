#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
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
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef double dbl;
typedef vector<bool> Vb;
typedef vector<char> Vc;
typedef vector<double> Vd;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<string> Vs;
typedef vector<vector<int>> VVi;
typedef vector<vector<ll>> VVl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }
inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

const int inf = 1 << 30;
const ll linf = 1LL << 60;
const int MOD = 1000000007;

using G = vector<vector<int>>;
typedef tuple<int, int, int> tup;

G g;
int n, m, start, goal;
Vl d, k, kk;
ll z = 0;

void debug();

void init()
{
	cin >> n >> m;
	g.resize(n);
	d.resize(n, linf);
	k.resize(n, linf);
	kk.resize(n, linf);

	REP(i, m)
	{
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
	}

	cin >> start >> goal;
	--start; --goal;
	d[start] = 0;
}

void bfs()
{
	// tup < d, vertex >
	priority_queue<pli> qk, qkk, qkkp;

	for (int u : g[start])
	{
		chmin(k[u], z);
		qk.push(pli(z, u));
	}

	while (!qk.empty())
	{
		while (!qk.empty())
		{
			ll c = qk.top().first;
			int v = qk.top().second;
			qk.pop();

			for (int u : g[v])
				if (chmin(kk[u], c))
					qkk.push(pli(c, u));
		}

		while (!qkk.empty())
		{
			ll c = qkk.top().first;
			int v = qkk.top().second;
			qkk.pop();

			for (int u : g[v])
				if (chmin(d[u], c + 1))
					qkkp.push(pli(d[u], u));
		}

		while (!qkkp.empty())
		{
			int v = qkkp.top().second;
			qkkp.pop();

			for (int u : g[v])
				if (chmin(k[u], d[v]))
					qk.push(pli(d[v], u));
		}
	}

}

int main()
{
	init();

	bfs();

	if (d[goal] == linf)
		cout << -1 << endl;
	else
		cout << d[goal] << endl;

}


void debug()
{
	cout << " d : ";
	REP(i, n)
		cout << setw(3) << d[i];
	cout << endl;

	cout << " k : ";
	REP(i, n)
		cout << setw(3) << k[i];
	cout << endl;

	cout << "kk : ";
	REP(i, n)
		cout << setw(3) << kk[i];
	cout << endl;

}

//// done E in 53min on 29th, Sep, 2019 ////
