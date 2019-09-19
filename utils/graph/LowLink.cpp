#include "template.h"

/*
	
	Low-Link Algorithm

	O( V + E )

	It finds bridges and articulation points of a undirected graph.
	Results will be stored in a vector defined at global scope.

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////

int n;
vector<vector<int>> g;
vector<pair<int, int>> bridge;
vector<int> articulation;

vector<bool> visited;
vector<int> ord;
vector<int> low;


//// BODY ////

template <class T>
void lowlink(const T v, const T par, int k = 0)
{
	ord[v] = low[v] = k;
	visited[v] = true;

	bool is_articulation = false;
	int cnt = 0;

	for (T adj : g[v])
	{
		if (!visited[adj])
		{
			++cnt;
			lowlink(adj, v, k + 1);
			low[v] = min(low[v], low[adj]);

			is_articulation |= (~par) && (ord[v] <= low[adj]);

			if (ord[v] < low[adj])
				bridge.emplace_back(minmax(v, adj));
		}
		else if (adj != par)
		{
			low[v] = min(low[v], ord[adj]);
		}
	}

	is_articulation |= (par == -1) && (cnt > 1);
	if (is_articulation)
		articulation.push_back(v);
}