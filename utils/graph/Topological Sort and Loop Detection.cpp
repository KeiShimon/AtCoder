#include "template.h"

/*
		Topological Sort + Loop Detection

		O ( |N| + |M| )

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////
int n, m;
vector<int> sorted;
vector<int> status;
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

bool dfs(int v)
{
	if (status[v] == 1) // Loop Detected !!
		return false;

	if (status[v] == 2) // Already Visited !!
		return true;

	++status[v];

	for (int adj : g[v])
		dfs(adj);

	++status[v];
	sorted.PB(v);
	return true;
}