#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)

typedef vector<bool> Vb;
typedef vector<int> Vi;
typedef vector<vector<int> > VVi;
typedef pair<int, int> P;
using G = vector<vector<int>>;

template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 1 << 28;

int n, m;
G g;
Vi shortestVisitPath, d;

int Dijkstra_return(int dest, const G& g);
void Dijkstra_visit();
void init();

int main()
{
	init();
	Dijkstra_visit();

	int ans = inf;
	REP1O(dest, n)
		if (d[dest] != inf)
			chmin(ans, d[dest] + Dijkstra_return(dest, g));

	if (ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;

}

void init()
{
	cin >> n >> m;
	g.resize(n, Vi(n, inf));

	REP(_i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[--a][--b] = c;
		g[b][a] = c;
	}
}

void Dijkstra_visit()
{
	vector<bool> done(n, false);
	shortestVisitPath.assign(n, -1);
	d.assign(n, inf);
	d[0] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(make_pair(0, 0));

	while (!que.empty())
	{
		auto c = que.top().first;
		int v = que.top().second;
		que.pop();
		done[v] = true;

		if (c > d[v])
			continue;

		REP(u, n)
			if (g[v][u] != inf && !done[u])
				if (chmin(d[u], d[v] + g[v][u]))
				{
					shortestVisitPath[u] = v;
					que.push(P(d[u], u));
				}
	}
}

int Dijkstra_return(int org, const G& g_orginal)
{
	G g(g_orginal);
	for (int x = org; ~shortestVisitPath[x]; x = shortestVisitPath[x])
	{
		int y = shortestVisitPath[x];
		g[x][y] = g[y][x] = inf;
	}

	Vb done(n, false);
	Vi d(n, inf);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(make_pair(0, org));

	while (!que.empty())
	{
		auto c = que.top().first;
		int v = que.top().second;
		done[v] = true;
		que.pop();

		if (c > d[v])
			continue;

		REP(u, n)
			if (g[v][u] != inf && !done[u])
				if (chmin(d[u], d[v] + g[v][u]))
					que.push(P(d[u], u));
	}

	return d[0];
}