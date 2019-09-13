#include "template.h"


/*
	Warshall–Floyd Algorithm

	O(V^3)

	It makes a 2d table of minimum distances between each pair of points.

*/


template <class T>
void warshall_froyd(vector<vector<T>>& v)
{
	int n{ (int)v.size() };

	REP(k, n)
		REP(i, n)
		REP(j, n)
		v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}
