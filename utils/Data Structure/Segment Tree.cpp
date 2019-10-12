#include "template.h"

/*
	
	Segment Tree

	O( log N ) for each query

*/

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
	void update(int i, const T & val);
	T operator[](const int& i) const { return tree[i + sz]; }
	T query(int a, int b);
};



//////// Segment Tree implementation ////////

template <class T> inline SegmentTree<T>::SegmentTree(int n, const F f, const T& I)
	: f(f), I(I)
	{	sz = 1; while (sz < n) sz <<= 1; tree.assign(2 * sz, I); }


template <class T> inline void SegmentTree<T>::set(int i, const T& val)
	{ tree[i + sz] = val; }

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
