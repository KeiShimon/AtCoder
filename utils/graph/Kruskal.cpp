#include "template.h"

/*
		Kruskal's algorithm

		O ( |E| log|E| )

		It finds minimum spanning tree from a graph.

*/


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////
typedef tuple<ll, int, int> tup;
auto compare = [](const tup& left, const tup& right) { return get<0>(left) < get<0>(right); };

int n, m, n_mst = 0;
ll c_mst = 0;
vector<tup> e, mst;
vector<int> parent;

//// BODY ////

void init()
{
	cin >> n >> m;
	e.reserve(m);
	parent.resize(n, -1);

	REP(i, m)
	{
		int a, b; ll c;
		cin >> a >> b >> c;

		if (a > b) swap(a, b);
		--a; --b;

		e.emplace_back(tup(c, a, b));
	}

	sort(ALL(e), compare);
}


int root(int a)
{
	if (parent[a] < 0)
		return a;
	return parent[a] = root(parent[a]);
}


bool unite(const tup& edge)
{
	int a = get<1>(edge);
	int b = get<2>(edge);
	ll c = get<0>(edge);

	int root_a = root(a);
	int root_b = root(b);

	if (root_a == root_b)
		return false;

	int size_a = -parent[root_a];
	int size_b = -parent[root_b];

	if (size_a < size_b)
	{
		swap(a, b); swap(size_a, size_b);
	}

	parent[a] += -size_b;
	parent[b] = a;

	++n_mst;
	c_mst += c;
	mst.emplace_back(edge);

	return true;
}

//
//int main()
//{
//	init();
//
//	for (auto edge : e)
//		unite(edge);
//
//	cout << c_mst << endl;
//}