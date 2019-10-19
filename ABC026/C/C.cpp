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

typedef vector<vector<int> > VVi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 1 << 28;

int n;
VVi g;

int dfs(int v)
{
	if (g[v].empty())
		return 1;

	if (g[v].size() == 1)
		return 1 + 2 * dfs(g[v][0]);

	int ma = 0, mi = inf;
	for (auto adj : g[v])
	{
		int x;
		x = dfs(adj);
		chmax(ma, x);
		chmin(mi, x);
	}

	return 1 + ma + mi;
}

int main()
{

	cin >> n;
	g.resize(n);

	REP(i, n - 1)
	{
		int b; cin >> b; --b;
		g[b].push_back(i + 1);
	}

	cout << dfs(0) << endl;
}
