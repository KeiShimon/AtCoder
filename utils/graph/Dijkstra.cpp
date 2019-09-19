#include "template.h"

/*
	
	Dijkstra Algorithm

	O( E logV )

	It determines minimum distances of each node a from given point

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////

int n;



//// BODY ////

template <class Tidx, class Tdist>
void Dijkstra(const Tidx frm, const vector<vector<pair<Tidx, Tdist>>>& g, vector<Tdist> d)
{
	vector<bool> done(n + 1, 0);
	priority_queue<pair<Tdist, Tidx>, vector<pair<Tdist, Tidx>>, greater<pair<Tdist, Tidx>>> que;

	que.emplace(MP((Tdist)0, frm));

	while (!que.empty())
	{
		Tdist cum = que.top().first;
		Tidx v = que.top().second;
		que.pop();
		done[v] = true;

		REP(i, SZ(g[v]))
		{
			Tidx adj = g[v][i].first;

			if (!done[adj])
				if (chmin(d[adj], cum + g[v][i].second))
					que.emplace(MP(d[adj], adj));
		}
	}
}