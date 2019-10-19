#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef vector<int> Vi;
typedef vector<vector<int> > VVi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 1 << 28;

template <class T>
void warshall_froyd(vector<vector<T>>& v)
{
	int n{ (int)v.size() };

	REP(k, n)
		REP(i, n)
		REP(j, n)
		v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
}

VVi d;
int n, m;

int main()
{
	cin >> n >> m;
	d.resize(n, Vi(n, inf));

	REP(i, n) d[i][i] = 0;

	REP(_i, m)
	{
		int a, b, t;
		cin >> a >> b >> t;
		--a; --b;

		d[a][b] = d[b][a] = t;
	}


	warshall_froyd(d);

	int ans = inf;
	REP(i, n)
	{
		int tmp = 0;
		REP(j, n)
			tmp = max(tmp, d[i][j]);

		ans = min(ans, tmp);
	}

	cout << ans << endl;
}
