#include "template.h"

//// MUST HAVE EXTERNAL VARIABLES ////

using G = vector<vector<int> >;

void init();
void bfs(int org, const G& g, vector<int>& d);

int n, m;
G g;
vector<int> d;

//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n);

	REP(_i, m)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].PB(b);
		// g[b].PB(a);
	}
}

void bfs(int org, const G& g, vector<int>& d)
{
	d.assign(n, -1);
	d[org] = 0;

	queue<int> que;
	que.push(org);

	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (auto u : g[v])
			if (!(~d[u]))
			{
				que.push(u);
				d[u] = d[v] + 1;
			}
	}
}