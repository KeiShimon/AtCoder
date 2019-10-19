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
#define PB push_back

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using G = vector<vector<int> >;

void init();
int bfs(int org, const G& g, vector<int>& d);

int n, m;
G g;
vector<int> d;


int main()
{
	init();

	REP(i, n)
		cout << bfs(i, g, d) << endl;

}

void init()
{
	cin >> n >> m;
	g.resize(n);

	REP(_i, m)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].PB(b);
		g[b].PB(a);
	}
}

int bfs(int org, const G& g, vector<int>& d)
{
	d.assign(n, -1);
	d[org] = 0;

	queue<int> que;
	que.push(org);

	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (auto u : g[v])
			if (!(~d[u]))
			{
				que.push(u);
				d[u] = d[v] + 1;
			}
	}

	int ret = 0;
	for (int x : d)
		if (x == 2)
			++ret;
	return ret;
}