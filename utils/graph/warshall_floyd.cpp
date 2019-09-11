#include "template.h"

template <class T>
void warshall_froyd(vector<vector<T>>& v)
{
	int n{ (int)v.size() };

	REP(k, n)
		REP(i, n)
		REP(j, n)
		v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}
