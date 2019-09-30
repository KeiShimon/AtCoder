#include "template.h"


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
