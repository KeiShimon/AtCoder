#include "template.h"


//// MUST HAVE EXTERNAL VARIABLES ////

using G = vector<vector<pair<ll, int>>>;
G g;

int n, m;
Vl d;
ll nul = linf;


//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n + 1);
	d.resize(n + 1, nul);

	REP(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g[a].emplace_back(MP(c, b));
	}
}


void dfs(int frm)
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