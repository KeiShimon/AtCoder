#include "template.h"

/*
		Topological Sort

		O ( |N| + |M| )

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////
int n, m;
vector<int> sorted;
vector<int> depth;
vector<vector<int>> g;

//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n);

	REP(i, m)
	{
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
	}
}

int dfs(int v)
{
	if (depth[v] != -1)
		return depth[v];

	int d = 1;
	for (int adj : g[v])
		chmax(d, 1 + dfs(adj));

	depth[v] = d;
	sorted.PB(v);
	return d;
}