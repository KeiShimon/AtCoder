#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef pair<int, int> P;
using G = vector<vector<P>>;

int Prim();
void init();

G g;
int h, w, sx, sy, gx, gy, n;
int p[101][101];
int id[101][101];
int ans;

int main()
{
	init();
	ans += Prim();
	cout << ans << endl;
}

void init()
{
	cin >> h >> w >> sx >> sy >> gx >> gy;
	n = h * w;

	int id_now = 0;
	REP(i, h) REP(j, w)
	{
		id[i][j] = id_now++;
		cin >> p[i][j];
		ans += p[i][j];
	}

	g.resize(n);

	REP(i, h) REP(j, w)
	{
		int val, u, v;

		v = id[i][j];

		if (i < h - 1)
		{
			u = id[i + 1][j];
			val = -p[i + 1][j] * p[i][j];

			g[v].push_back(P(val, u));
			if (v != id[sy][sx])
				g[u].push_back(P(val, v));
		}

		if (j < w - 1)
		{
			u = id[i][j + 1];
			val = -p[i][j + 1] * p[i][j];

			g[v].push_back(P(val, u));
			if (v != id[sy][sx])
				g[u].push_back(P(val, v));
		}
	}
}

int Prim()
{
	int ret = 0;

	vector<bool> done(n, false);

	priority_queue<P, vector<P>, greater<P> > que;
	que.push(P(0, id[sy][sx]));

	while (!que.empty())
	{
		int v = que.top().second;
		auto c = que.top().first;
		que.pop();

		if (!done[v])
		{
			done[v] = true;
			ret -= c;

			for (P& e : g[v])
				que.emplace(e);
		}
	}

	return ret;
}
