#include "template.h"

/*
	Prim's algorithm

	O( |E| log|E| )

	It finds minimum spanning tree for a weighted graph.

*/


//// MUST HAVE EXTERNAL VARIABLES ////
typedef pair<ll, int> P;
using G = vector<vector<P>>;

ll Prim();

G g;
int n;


//// BODY ////
ll Prim()
{
	vector<bool> done(n, false);
	ll ret = 0;

	REP(i, n)
	{
		if (!done[i])
		{
			priority_queue<P, vector<P>, greater<P> > que;
			que.push(P(0LL, i));

			while (!que.empty())
			{
				int v = que.top().second;
				auto c = que.top().first;
				que.pop();

				if (!done[v])
				{
					done[v] = true;
					ret += c;

					for (P e : g[v])
						que.push(e);
				}
			}
		}
	}

	return ret;
}