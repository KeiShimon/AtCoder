#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>
#include <functional>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

template< typename T >
struct SegmentTree {
	using F = function<T(T, T)>;
private:
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


void init();

const int max_w = 100000;
const int inf = 1 << 28;
int n;
vector <pair<int, int>> vb;

int comp(int left, int right) {return max(left, right); };
SegmentTree<int> seg(max_w, comp, -inf);

int main()
{
	init();

	seg.update(0, 0);

	for (auto box : vb)
	{
		int w = box.first;
		int h = -box.second;

		int tmp = 1 + seg.query(0, h);
		seg.update(h, tmp);
	}

	cout << seg.query(0, max_w + 1) << endl;

}

void init()
{
	cin >> n;

	REP(_i, n)
	{
		int w, h; cin >> w >> h;
		vb.PB(MP(w, -h));
	}
	sort(ALL(vb));
}

//////// Segment Tree implementation ////////

template <class T> inline SegmentTree<T>::SegmentTree(int n, const F f, const T& I)
	: f(f), I(I)
{
	sz = 1; while (sz < n) sz <<= 1; tree.assign(2 * sz, I);
}


template <class T> inline void SegmentTree<T>::set(int i, const T& val)
{
	tree[i + sz] = val;
}

template <class T> inline void SegmentTree<T>::build()
{
	for (int i = sz - 1; i > 0; i--)
		tree[i] = f(tree[2 * i], tree[2 * i + 1]);
}


template <class T> inline void SegmentTree<T>::update(int i, const T& val)
{
	i += sz;
	tree[i] = val;
	while (i >>= 1)
		tree[i] = f(tree[2 * i], tree[2 * i + 1]);
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

//////// The END of Segment Tree implementation ////////
