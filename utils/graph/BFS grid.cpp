#include "template.h"



//// MUST INCLUDE ////
#include <queue>



//// MUST HAVE EXTERNAL VARIABLES ////

int h, w;
vector<string> field;
const char PATH = '.';
const char WALL = '#';
const int ndir = 4;
const int vx[ndir] = { 0, 1, 0, -1 };
const int vy[ndir] = { 1, 0, -1, 0 };



//// BODY ////

template <class Tidx, class Tdist>
void bfs(vector<vector<Tdist>>& d, const Tidx sy, const Tidx sx, const Tidx gy = -1, const Tidx gx = -1)
{
	queue<pair<Tidx, Tidx>> que{ MP(sy, sx) };

	while (!que.empty())
	{
		int y = que.top().first;
		int x = que.top().second;
		que.pop();

		if (y == gy && x == gx)
			return;

		for (int i{ 0 }; i < ndir; i++)
		{
			Tidx newx = x + dx[i];
			Tidx newy = y + dy[i];

			if (0 <= newx && newx < w && 0 <= newy && newy < h)
				if (field[newy][newx] == PATH)
					if (chmin(d[newy][newx], d[y][x] + 1))
						que.emplace(MP(newy, newx));
		}
	}

	return -1;
}
