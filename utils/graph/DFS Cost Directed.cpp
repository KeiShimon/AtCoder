#include "template.h"



//// MUST INCLUDE ////
#include <queue>



//// MUST HAVE EXTERNAL VARIABLES ////

int n, m;
vector<vector<pair<int, ll>>> g;
vll loc;
ll nul{ LLMAX };



//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n + 1);
	loc.resize(n + 1, LLMAX);

	REP(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g[a].emplace_back(MP(b, c));
	}
}


template <class Tidx, class Tdist>
void dfs(const vector<vector<pair<Tidx, Tdist>>>& g, vector<Tdist>& d, const Tidx frm)
{
	queue<Tidx> que;
	que.push(frm);
	d[frm] = 0;

	while (!que.empty())
	{
		Tidx v = que.top(); que.pop();

		REP(i, SZ(g[v]))
		{
			Tidx adj = g[v][i].first;
			Tdist c = g[v][i].second;

			if (d[adj] == nul)
			{
				d[adj] = d[v] + c;
				que.PB(adj);
			}
		}
	}
}