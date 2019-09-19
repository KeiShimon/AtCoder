#include "template.h"

/*
	Bellman-Ford Algorithm

	O( |E||V| )

	It finds distance from a starting point to each node.
	The benefit of using this algoerithm is that
	it can be used when there can be a negative edges and loops.

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////

typedef pair<ll, int> P;
int n, m;
vector<vector<P>> g;
vll d; // init INF!!
ll INF;

//// BODY ////

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


vector<bool> negative;

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
