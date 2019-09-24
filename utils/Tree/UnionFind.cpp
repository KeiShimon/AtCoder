#include "template.h"



//// MUST HAVE EXTERNAL VARIABLES ////
vector<int> parent;
int root(int);
bool unite(int, int);


//// BODY ////

int root(int a)
{
	if (parent[a] < 0)
		return a;
	return parent[a] = root(parent[a]);
}


bool unite(int a, int b)
{
	int root_a = root(a);
	int root_b = root(b);

	if (root_a == root_b)
		return false;

	int size_a = -parent[root_a];
	int size_b = -parent[root_b];

	if (size_a < size_b)
	{
		swap(a, b); swap(size_a, size_b); swap(root_a, root_b);
	}

	parent[root_a] += -size_b;
	parent[root_b] = root_a;

	return true;
}
