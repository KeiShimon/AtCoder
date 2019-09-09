#include "template.h"

int rows, cols;
vector<string> field;
vector<vector<int>> dist;
const char ALLOWED = '.';

int bfs(const int sy, const int sx, const int gy, const int gx)
{
	deque<tupiii> q{ make_tuple(sy, sx, 0) };

	int x, y, d;
	while (!q.empty())
	{
		y = get<0>(q.front());
		x = get<1>(q.front());
		d = get<2>(q.front());
		q.pop_front();

		if (y == gy && x == gx)
			return d;

		for (int i{ 0 }; i < 4; i++)
		{
			if (0 <= x + dx[i] && x + dx[i] < cols && 0 <= y + dy[i] && y + dy[i] < rows)
				if (field[y + dy[i]][x + dx[i]] == ALLOWED && dist[y + dy[i]][x + dx[i]] == INTMAX)
				{
					q.emplace_back(make_tuple(y + dy[i], x + dx[i], d + 1));
					dist[y + dy[i]][x + dx[i]] = d + 1;
				}
		}
	}

	return -1;
}