#include "template.h"

/*
	Prim's algorithm

	O( |E| log|E| )

	It finds minimum spanning tree for a weighted graph.

*/


//// MUST INCLUDE ////
typedef pair<ll, int> P;


//// MUST HAVE EXTERNAL VARIABLES ////
int n;
vector<vector<P>> g;


//// BODY ////
ll Prim()
{
	vector<bool> done(n, false);
	ll tot = 0;

	REP(i, n)
	{
		if (!done[i])
		{
			priority_queue<P, vector<P>, greater<P>> que;
			que.push(MP(0LL, i));

			while (!que.empty())
			{
				int v = que.top().second;
				ll c = que.top().first;
				que.pop();

				if (!done[v])
				{
					done[v] = true;
					tot += c;

					for (P adj : g[v])
						que.push(adj);
				}
			}
		}
	}

	return tot;
}