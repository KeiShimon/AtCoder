#include "template.h"

/*

	DFS for Tree

	O( N )

	It determines minimum distances of each node a from given point

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////

int n;
vector<vector<int>> g;


//// BODY ////

void init()
{
	cin >> n;
	g.resize(n);

	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void dfs(int v, int par)
{
	// pre-order operations if any

	for (int u : g[v])
	{
		if (u != par)
		{
				
		}
	}

	// post-order operations if any

}
