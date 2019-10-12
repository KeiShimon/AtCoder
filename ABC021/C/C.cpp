#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define PB push_back

typedef int64_t ll;
typedef vector<bool> Vb;
typedef vector<int> Vi;

const int MOD = 1000000007;

////// Mod int //////
struct mint {
	ll x;
	mint() :x(0) {}
	mint(ll x) :x((x% MOD + MOD) % MOD) {}
	// mint(ll x):x(x){}
	mint& fix() { x = (x % MOD + MOD) % MOD; return *this; }
	mint operator-() const { return mint(0) - *this; }
	mint& operator+=(const mint& a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
	mint& operator-=(const mint& a) { if ((x += MOD - a.x) >= MOD) x -= MOD; return *this; }
	mint& operator*=(const mint& a) { (x *= a.x) %= MOD; return *this; }
	mint operator+(const mint& a)const { return mint(*this) += a; }
	mint operator-(const mint& a)const { return mint(*this) -= a; }
	mint operator*(const mint& a)const { return mint(*this) *= a; }
	bool operator<(const mint& a)const { return x < a.x; }
	bool operator==(const mint& a)const { return x == a.x; }
};
istream& operator>>(istream& i, mint& a) { i >> a.x; return i; }
ostream& operator<<(ostream& o, const mint& a) { o << a.x; return o; }
typedef vector<mint> Vm;

/////////////////////

using G = vector<vector<int> >;

void init();
void bfs(int org, const G& g, vector<int>& d);
void shortestPath();

int n, m, a, b;
G g;
Vi d;
Vb ok;
Vm ans;

int main()
{
	init();

	bfs(a, g, d);
	shortestPath();

	ans.resize(n, 0);
	ans[a] = 1;

	for (int dist = 1; dist <= d[b]; ++dist)
	{
		REP(v, n)
			if (ok[v] && d[v] == dist)
			{
				for (int u : g[v])
					if (ok[u] && d[u] == dist - 1)
						ans[v] += ans[u];
			}
	}

	cout << ans[b] << endl;
}

void init()
{
	cin >> n >> a >> b >> m;
	--a; --b;

	g.resize(n);
	ok.resize(n, false);
	REP(_i, m)
	{
		int x, y;
		cin >> x >> y;
		--x; --y;
		g[x].PB(y);
		g[y].PB(x);
	}
}

void shortestPath()
{
	queue<int> que;
	que.push(a);
	ok[a] = true;

	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (int u : g[v])
		{
			if (d[u] == d[v] + 1 && !ok[u])
			{
				ok[u] = true;
				que.push(u);
			}
		}
	}
}

void bfs(int org, const G& g, vector<int>& d)
{
	d.assign(n, -1);
	d[org] = 0;

	queue<int> que;
	que.push(org);

	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (auto u : g[v])
			if (!(~d[u]))
			{
				que.push(u);
				d[u] = d[v] + 1;
			}
	}
}