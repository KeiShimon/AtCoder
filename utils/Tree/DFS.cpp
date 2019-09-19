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
vector<bool> visited;


//// BODY ////

void init()
{
	cin >> n;
	g.resize(n + 1);
	visited.resize(n + 1);

	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;

		g[a].push_back(b);
		g[b].push_back(a);
	}
}

template <class Tidx>
void dfs(Tidx v, Tidx frm)
{
	// pre-order operations if any
	visited[v] = true;


		for (Tidx adj : g[v])
		{
			if (!visited[adj])
			{
				
			}
		}

		// post-order operations if any

	}
}

