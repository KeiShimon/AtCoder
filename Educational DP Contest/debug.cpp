#include "template.h"

template <class T>
void print(const vector<vector<T>>& v)
{
	REP(i, SZ(v))
	{
		REP(j, SZ(v[i]))
			cout << v[i][j] << " ";
		cout << endl;
	}
}