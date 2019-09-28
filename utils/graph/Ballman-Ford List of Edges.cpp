#include "template.h"
extern const ll linf;

/*
	Bellman-Ford Algorithm

	O( |V||E| )

	It finds distance from a starting point to each node.
	Bellman-Ford algorithm is useful when there can be negative edges and loops.

*/


//// MUST HAVE EXTERNAL VARIABLES ////

typedef tuple <int, int, ll> tup;
vector<tup> edges;

int n, m;
vector<ll> d;


//// BODY ////

void init()
{
	cin >> n >> m;

	d.resize(n, linf);
	edges.reserve(m);

	REP(_i, m)
	{
		int a, b; ll c; cin >> a >> b >> c; --a; --b;
		edges.emplace_back(tup(a, b, c));
	}
}

template <class Td>
bool Bellman_Ford(int src, const vector<tup>& edges, vector<Td>& d)
{
	d[src] = 0;

	REP(_i, n - 1)
	{
		for (tup edge : edges)
		{
			int a = get<0>(edge);
			int b = get<1>(edge);
			Td c = get<2>(edge);
			chmin(d[b], d[a] + c);
		}
	}

	for (tup edge : edges)
	{
		int a = get<0>(edge);
		int b = get<1>(edge);
		Td c = get<2>(edge);

		if (chmin(d[b], d[a] + c))
			return true;
	}

	return false;
}


vector<bool> loop;

// detect all vertices that are affected by any negative loop : cost of those nodes would be infinitely updated
template <class Td>
void detectLoopingVertices(const vector<tup>& edges, vector<Td>& d)
{
	loop.assign(n, false);

	REP(_i, n)
	{
		for (tup edge : edges)
		{
			int a = get<0>(edge);
			int b = get<1>(edge);
			Td c = get<2>(edge);

			if (chmin(d[b], d[a] + c))
				loop[b] = true;
			if (loop[a])
				loop[b] = true;
		}
	}
}
