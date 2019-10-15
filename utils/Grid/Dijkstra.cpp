#include "template.h"

const ll linf = 1LL << 55;
const char WALL = '#';
const char PATH = '.';
const int n_dir = 4;
const int dx[]{ 0, 1,  0, -1 };
const int dy[]{ 1, 0, -1,  0 };
int h, w, sx, sy, gx, gy;
ll x, t;
Vs f;
Vl d;
VVi id;

void init();
bool Dijkstra(ll x);

void init()
{
	cin >> h >> w >> t;
	d.resize(h * w);
	id.resize(h, Vi(w));
	f.resize(h);
	int cur = 0;

	REP(i, h)
	{
		cin >> f[i];
		REP(j, w)
		{
			id[i][j] = cur++;

			if (f[i][j] == 'S')
			{
				sx = j; sy = i;
				f[i][j] = PATH;
			}
			else if (f[i][j] == 'G')
			{
				gx = j; gy = i;
				f[i][j] = PATH;
			}
		}
	}
}

bool Dijkstra(ll cost_wall)
{
	using P = pair<ll, int>;

	Vb done(h * w, false);
	REP(i, h) REP(j, w)
		d[id[i][j]] = linf;
	d[id[sy][sx]] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(MP(0, id[sy][sx]));

	while (!que.empty())
	{
		ll c = que.top().first;
		int i = que.top().second;
		int y = i / w, x = i % w;
		done[i] = true;
		que.pop();

		if (c > d[i])
			continue;

		REP(dir, n_dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (0 <= ny && 0 <= nx && ny < h && nx < w)
			{
				int ni = id[ny][nx];
				if (!done[ni])
				{
					if (f[ny][nx] == PATH)
					{
						if (chmin(d[ni], 1 + d[i]))
							que.push(MP(d[ni], ni));
					}
					else if (chmin(d[ni], cost_wall + d[i]))
					{
						que.push(MP(d[ni], ni));
					}
				}
			}
		}
	}


	if (d[id[gy][gx]] <= t)
		return true;
	else
		return false;
}