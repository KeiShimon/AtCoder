#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

typedef int64_t ll;

const int MOD = 1000000007;

// Mod int
struct mint {
	ll x;
	mint() :x(0) {}
	mint(ll x) :x((x% MOD + MOD) % MOD) {}
	// mint(ll x):x(x){}
	mint& fix() { x = (x % MOD + MOD) % MOD; return *this; }
	mint operator-() const { return mint(0) - *this; }
	mint& operator+=(const mint& a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
	mint& operator-=(const mint& a) { if ((x += MOD - a.x) >= MOD) x -= MOD; return *this; }
	mint& operator*=(const mint& a) { (x *= a.x) %= MOD; return *this; }
	mint operator+(const mint& a)const { return mint(*this) += a; }
	mint operator-(const mint& a)const { return mint(*this) -= a; }
	mint operator*(const mint& a)const { return mint(*this) *= a; }
	bool operator<(const mint& a)const { return x < a.x; }
	bool operator==(const mint& a)const { return x == a.x; }
};
istream& operator>>(istream& i, mint& a) { i >> a.x; return i; }
ostream& operator<<(ostream& o, const mint& a) { o << a.x; return o; }
typedef vector<mint> Vm;

////////////////////////////////////////////////////////////////////////////////////

template <class T> class BinaryIndexedTree {
	// it can handle  n  items of index [0, n)
	// throw indices as-is

	vector<T> tree;
	int N_ELEMS;
	int TREE_SIZE;

public:
	BinaryIndexedTree(int n) : tree(n + 2, (T)0), N_ELEMS{ n }, TREE_SIZE{ n + 2 } {}
	BinaryIndexedTree() : BinaryIndexedTree(1000) {}

	// only internal process is 1-indexed so when using forget about complex indexing

	void init(int n) { tree.assign(n + 2, (T)0); this->N_ELEMS = n; this->TREE_SIZE = n + 2; }
	void add(int a, T val) { for (++a; a < TREE_SIZE; a += a & (-a)) tree[a] += val; }
	T query(int a) { T ret{ 0 }; for (++a; a > 0; a -= a & (-a)) ret += tree[a]; return ret; }
	T query(int left, int right) { return query(right - 1) - query(left - 1); }
	T getData(int a) { return query(a) - query(a - 1); }
	T operator[](int a) { return getData(a); }
};

const int MAX_N = 100005;

BinaryIndexedTree<mint> cumDP(MAX_N);
int n, m, l;
int mostRecent[MAX_N];

int main()
{
	cin >> n >> m;

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	cumDP.add(0, 1);

	REP1C(r, n)
	{
		int f; cin >> f;
		l = max(l, mostRecent[f]);

		cumDP.add(r, cumDP.query(l, r));

		mostRecent[f] = r;
	}

	cout << cumDP.getData(n) << endl;
}
