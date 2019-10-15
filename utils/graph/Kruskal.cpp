#include "template.h"

/*
		Kruskal's algorithm

		O ( |E| log|E| )

		It finds minimum spanning tree from a graph.

*/


//// MUST INCLUDE ////

class UnionFind {
	vector<int> parent;
	void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }
public:
	UnionFind() {}
	UnionFind(int n) : parent(n, -1) {}
	void init(int n);
	int root(int a);
	bool unite(int a, int b);
	int size(int a);
	int count();
	bool operator() (int a, int b);
	int operator[] (int i);
};


//// MUST HAVE EXTERNAL VARIABLES ////

typedef tuple<ll, int, int> tup;
auto compare = [](const tup& left, const tup& right) { return get<0>(left) < get<0>(right); };
ll Kruskal(const vector<tup>& g, UnionFind& uf);
void init();

UnionFind uf;
int n, m;
ll c_mst = 0;
vector<tup> edges, mst;

//// BODY ////

void init()
{
	cin >> n >> m;
	edges.reserve(m);
	uf.init(n);

	REP(i, m)
	{
		int a, b; ll c;
		cin >> a >> b >> c;

		if (a > b) swap(a, b);
		--a; --b;

		edges.emplace_back(tup(c, a, b));
	}

	sort(ALL(edges), compare);
}

ll Kruskal(const vector<tup>& g, UnionFind& uf)
{
	ll mst_size = 0;

	for (auto e : edges)
	{
		if (uf.unite(get<1>(e), get<2>(e)))
			mst_size += get<0>(e);
	}

	return mst_size;
}

inline void UnionFind::init(int n) { parent.assign(n, -1); }
inline int UnionFind::size(int a) { return -parent[root(a)]; }
inline int UnionFind::count() { int ret = 0; for (int x : parent) if ((1 << 31) & x) ++ret; return ret; }
inline bool UnionFind::operator() (int a, int b) { return unite(a, b); }
inline int UnionFind::operator[](int i) { return root(i); }
inline int UnionFind::root(int a) { return (parent[a] < 0) ? a : parent[a] = root(parent[a]); }
inline bool UnionFind::unite(int a, int b)
{
	int root_a = root(a), root_b = root(b);
	if (root_a == root_b) return false;

	int size_a = -parent[root_a], size_b = -parent[root_b];
	if (size_a < size_b) swap(a, b), swap(size_a, size_b), swap(root_a, root_b);

	parent[root_a] += -size_b;
	parent[root_b] = root_a;
	return true;
}
