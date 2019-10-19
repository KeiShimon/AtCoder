#include "template.h"

/*
	Euler Tour

	O ( N ) 

*/

int n;
vector<vector<int>> g;
vector<int> vs;
vector<int> depth;

void init()
{
	cin >> n;
	g.resize(n);
	vs.resize(2 * n - 1);
	depth.resize(2 * n - 1);

	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

void dfs(int v, int par, int& k, int d)
{
	vs[k] = v;
	depth[k++] = d;

	for (int u : g[v])
	{
		if (u != par)
		{
			dfs(u, v, k, d + 1);
			vs[k] = v;
		}
	}
}
