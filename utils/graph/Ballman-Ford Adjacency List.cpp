#include "template.h"
extern const ll linf;

/*
	Bellman-Ford Algorithm

	O( |E||V| )

	It finds distance from a starting point to each node.
	Bellman-Ford algorithm is useful when there can be negative edges and loops.

*/



//// MUST HAVE EXTERNAL VARIABLES ////

int n, m;
vector<vector<pair<ll, int>>> g;
vector<ll> d;

//// BODY ////

void init()
{
	cin >> n >> m;

	g.resize(n);
	d.resize(n, linf);

	REP(_i, m)
	{
		int a, b; ll c; cin >> a >> b >> c; --a; --b;
		g[a].emplace_back(MP(c, b));
	}
}

template <class Td>
bool Bellman_Ford(int src, const vector<vector<pair<Td, int>>>& g, vector<Td>& d)
{
	int n = g.size();
	d[src] = (Td)0;

	REP(i, n - 1)
		REP(v, n)
		REP(i, SZ(g[v]))
	{
		int adj = g[v][i].second;
		Td c = g[v][i].first;
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


vector<bool> loop;

// detect all vertices that are affected by any negative loop : cost of those nodes would be infinitely updated
template <class Td>
void detectLoopingVertices(const vector<vector<pair<Td, int>>>& g, vector<Td>& d)
{
	int n = g.size();
	loop.assign(n, false);

	REP(i, n)
		REP(v, SZ(g))
		REP(i, SZ(g[v]))
	{
		int adj = g[v][i].second;
		ll c = g[v][i].first;
		if (chmin(d[adj], d[v] + c))
			loop[adj] = true;

		if (loop[v])
			loop[adj] = true;
	}
}
