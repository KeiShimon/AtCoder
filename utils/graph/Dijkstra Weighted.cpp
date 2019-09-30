#include "template.h"

/*
	
	Dijkstra Algorithm

	O( E logV )

	It determines minimum distances of each node a from given point

*/


//// MUST HAVE EXTERNAL VARIABLES ////

using G = vector<vector<pli>>;

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
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].PB(MP(c, b));
		// g[b].PB(MP(c, a));
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

		for (P p : g[v])
			if (!done[p.second] && chmin(d[p.second], c + p.first))
				que.push(P(d[p.second], p.second));
	}
}