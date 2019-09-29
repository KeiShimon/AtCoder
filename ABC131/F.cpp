#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<bool> Vb;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<vector<int>> VVi;
typedef vector<vector<ll>> VVl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;


class UnionFind {
	vector<int> parent;
public:
	UnionFind() {}
	UnionFind(int n) : parent(n + 1, -1) {}
	void init(int n);
	int root(int a);
	bool unite(int a, int b);
	int size(int a);
	bool operator() (int a, int b);
	int operator[] (int i);
};

int n;
Vi vx, vy;
map<int, int> mx, my;
vector<set<int>> vsx, vsy;
UnionFind uf;

void init()
{
	cin >> n;
	vx.resize(n);
	vy.resize(n);
	vsx.resize(n);
	vsy.resize(n);
	uf.init(n);

	REP(i, n)
	{
		int x, y; cin >> x >> y;
		vx[i] = x;
		vy[i] = y;

		if (mx.count(x)) uf.unite(i, mx[x]);
		mx[x] = i;
		if (my.count(y)) uf.unite(i, my[y]);
		my[y] = i;
	}
}

int main()
{
	init();

	REP(i, n)
	{
		vsx[uf.root(i)].insert(vx[i]);
		vsy[uf.root(i)].insert(vy[i]);
	}

	ll ans = 0;
	REP(i, n)
		ans += 1LL * SZ(vsx[i]) * SZ(vsy[i]);

	cout << ans - n << endl;
}


inline void UnionFind::init(int n)
{
	parent.assign(n + 1, -1);
}

inline int UnionFind::size(int a)
{
	return -parent[root(a)];
}

inline bool UnionFind::operator() (int a, int b)
{
	return unite(a, b);
}

inline int UnionFind::operator[](int i)
{
	return root(i);
}

inline int UnionFind::root(int a)
{
	return (parent[a] < 0) ? a : parent[a] = root(parent[a]);
}

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
