#include "template.h"

/*

	Dijkstra Algorithm

	O( E logV )

	It determines minimum distances of each node a from given point

*/


//// MUST HAVE EXTERNAL VARIABLES ////

using G = vector<vector<int>>;

template <class Tdist>
void Dijkstra(int org, const G& g, vector<Tdist>& d);

int n, m;
G g;
Vl d;
const ll INF = linf;

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

template <class Tdist>
void Dijkstra(int org, const G& g, vector<Tdist>& d)
{
	using P = pair<Tdist, int>;

	vector<bool> done(n, false);
	d.assign(n, INF);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P((Tdist)0, org));

	while (!que.empty())
	{
		Tdist c = que.top().first;
		int v = que.top().second;
		que.pop();
		done[v] = true;

		if (c > d[v])
			continue;

		for (auto u : g[v])
			if (!done[u] && chmin(d[u], c + 1))
				que.push(P(d[u], u));
	}
}