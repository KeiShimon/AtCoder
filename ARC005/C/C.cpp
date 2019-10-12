#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define MP make_pair

using namespace std;

inline void YES() { cout << "YES" << endl; } inline void NO() { cout << "NO" << endl; }
inline void Yes() { cout << "Yes" << endl; } inline void No() { cout << "No" << endl; }

const char WALL = '#';
const char PATH = '.';
const int dx[]{ 0, 1,  0, -1 };
const int dy[]{ 1, 0, -1,  0 };
int h, w, sx, sy, gx, gy;
vector<string> f;
vector<vector<int>> d;

void bfs(int sy, int sx, int gy, int gx, vector<vector<int>>& d)
{

	d[sy][sx] = 0;
	deque<pair<int, int>> que;
	que.push_front(MP(sy, sx));

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop_front();

		REP(dir, 4)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (0 <= ny && 0 <= nx && ny < h && nx < w)
			{
				if (d[ny][nx] == -1)
				{
					if (f[ny][nx] == PATH)
					{
						que.push_front(MP(ny, nx));
						d[ny][nx] = d[y][x];
					}
					else
					{
						que.push_back(MP(ny, nx));
						d[ny][nx] = d[y][x] + 1;
					}
				}
			}
		}
	}
}

void init()
{
	cin >> h >> w;
	f.resize(h);
	REP(i, h)
	{
		cin >> f[i];
		REP(j, w)
		{
			if (f[i][j] == 's')
				sx = j, sy = i, f[i][j] = PATH;
			if (f[i][j] == 'g')
				gx = j, gy = i, f[i][j] = PATH;
		}
	}
	d.resize(h, vector<int>(w, -1));
}


int main()
{
	init();
	bfs(sy, sx, gy, gx, d);

	if (d[gy][gx] > 2)
		NO();
	else
		YES();
}
