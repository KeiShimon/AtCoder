#include "template.h"

/*
		BFS on Grid

		O ( H * W )

*/


//// MUST HAVE EXTERNAL VARIABLES ////
const char WALL = '#';
const char PATH = '.';
const int n_dir = 4;
const int dx[]{ 0, 1,  0, -1 };
const int dy[]{ 1, 0, -1,  0 };
int h, w;
vector<string> f;
vector<vector<int>> d;

//// BODY ////

void init()
{
	cin >> h >> w;
	f.resize(h);
	REP(i, h)
		cin >> f[i];

	d.resize(h, vector<int>(w, -1));
}

void bfs(int sy, int sx, int gy, int gx, vector<vector<int>>& d)
{
	d[sy][sx] = 0;
	queue<pair<int, int>> que;
	que.push(MP(sy, sx));

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		REP(dir, n_dir)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (0 <= ny && 0 <= nx && ny < h && nx < w)
				if(f[ny][nx] == PATH)
					if (d[ny][nx] == -1)
					{
						que.push(MP(ny, nx));
						d[ny][nx] = 1 + d[y][x];
					}
		}
	}
}