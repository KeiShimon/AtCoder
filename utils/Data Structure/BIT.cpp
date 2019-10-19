#include "template.h"

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

////////////////////////////////////////////////////////////////////////////////////