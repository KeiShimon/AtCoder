#include "template.h"



//// MUST INCLUDE ////
#include <queue>



//// MUST HAVE EXTERNAL VARIABLES ////

int n, m;
vector<vector<pair<ll, int>>> g;
vll d;
ll nul{ LLMAX };


//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n + 1);
	d.resize(n + 1, LLMAX);

	REP(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g[a].emplace_back(MP(c, b));
	}
}


void dfs(const int frm)
{
	queue<int> que;
	que.push(frm);
	d[frm] = 0;

	while (!que.empty())
	{
		int v = que.front(); que.pop();

		REP(i, SZ(g[v]))
		{
			int adj = g[v][i].first;
			ll c = g[v][i].second;

			if (d[adj] == nul)
			{
				d[adj] = d[v] + c;
				que.push(adj);
			}
		}
	}
}