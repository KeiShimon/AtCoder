#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

template< typename T >
class SegmentTree {
	using F = function<T(T, T)>;

	int sz;
	vector<T> tree;
	const F f;
	const T I; // identity element

public:
	SegmentTree(int n, const F f, const T& I);
	void set(int i, const T& val);
	void build();
	void update(int i, const T& val);
	T operator[](const int& i) const { return tree[i + sz]; }
	T query(int a, int b);
};

////////////////////////////////////////////////////////////////////////////////////

void init();
void dfs(int v, int par, int& k, int d);
int getLCA(int a, int b);

const int MAX_N = 100000;
int n, q;
vector<vector<int>> g;
vector<int> visitNode, depth, id;

const int inf = 1 << 28;
typedef pair<int, int> P;
P compare(P l, P r) { return (l.first < r.first) ? l : r; }
SegmentTree<P> seg(2 * MAX_N - 1, compare, P(inf, -1));

int getLCA(int a, int b)
{
	return seg.query(min(id[a], id[b]), max(id[a], id[b]) + 1).second;
}

int main()
{
	cin >> n;
	init();

	cin >> q;
	REP(_i, q)
	{
		int a, b; cin >> a >> b; --a; --b;

		int lca = getLCA(a, b);
		int lca_depth = depth[id[lca]];

		int ans = 1 + (depth[id[a]] - lca_depth) + (depth[id[b]] - lca_depth);

		cout << ans << endl;
	}
}

void init()
{
	g.resize(n);
	id.resize(n);
	visitNode.resize(2 * n - 1);
	depth.resize(2 * n - 1);

	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int k = 0;
	dfs(0, -1, k, 0);

	seg.build();
}

void dfs(int v, int par, int& k, int d)
{
	id[v] = k;
	visitNode[k] = v;
	depth[k] = d;
	seg.set(k, P(d, v));
	k++;

	for (int u : g[v])
	{
		if (u != par)
		{
			dfs(u, v, k, d + 1);
			visitNode[k] = v;
			depth[k] = d;
			seg.set(k, P(d, v));
			k++;
		}
	}
}

//////// Segment Tree implementation ////////

template <class T> inline SegmentTree<T>::SegmentTree(int n, const F f, const T& I)
	: f(f), I(I) {
	sz = 1; while (sz < n) sz <<= 1; tree.assign(2 * sz, I);
}

template <class T> inline T SegmentTree<T>::query(int a, int b)
{
	T L = I, R = I;
	for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
	{
		if (a & 1) L = f(L, tree[a++]);
		if (b & 1) R = f(tree[--b], R);
	}
	return f(L, R);
}

template <class T> inline void SegmentTree<T>::set(int i, const T& val) { tree[i + sz] = val; }
template <class T> inline void SegmentTree<T>::build() { for (int i = sz - 1; i > 0; i--) tree[i] = f(tree[2 * i], tree[2 * i + 1]); }
template <class T> inline void SegmentTree<T>::update(int i, const T& val) { i += sz; tree[i] = val; while (i >>= 1) tree[i] = f(tree[2 * i], tree[2 * i + 1]); }

//////// The END of Segment Tree implementation ////////
