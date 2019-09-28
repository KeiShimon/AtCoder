#include "template.h"

/*
	
	Dijkstra Algorithm

	O( E logV )

	It determines minimum distances of each node a from given point

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////

typedef pair<ll, int> P;
template <class Tidx, class Tdist>
void Dijkstra(const Tidx org, const vector<vector<pair<Tdist, Tidx>>>& g, vector<Tdist>& d);

int n, m;
const ll inf = 1LL << 60;
vector<vector<P>> g;
vll d;


//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n + 1);

	REP(_i, m)
	{
		int a, b; ll c;
		cin >> a >> b >> c;

		g[a].PB(MP(c, b));
	}
}

template <class Tidx, class Tdist>
void Dijkstra(const Tidx org, const vector<vector<pair<Tdist, Tidx>>>& g, vector<Tdist>& d)
{
	using P = pair<Tdist, Tidx>;

	vector<bool> done(n + 1, false);
	d.assign(n + 1, inf);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(MP((Tdist)0, org));

	while (!que.empty())
	{
		Tdist c = que.top().first;
		Tidx v = que.top().second;
		que.pop();
		done[v] = true;

		for (P p : g[v])
			if (!done[p.second] && chmin(d[p.second], c + p.first))
				que.push(MP(d[p.second], p.second));
	}
}