#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

#define MP(x, y) make_pair(x, y)

typedef pair<int, int> mytup;

const int DX[4]{-1, 1,  0, 0};
const int DY[4]{ 0, 0, -1, 1};
const int INF{ 1000000000 };

class C {
	int ROWS, COLUMNS;
	int sx, sy, gx, gy;
	vector<vector<bool>> field;
	vector<vector<int>> cost_table;

public:
	void solve()
	{
		field.resize(ROWS);
		cost_table.resize(ROWS);

		for (int y{ 0 }; y < ROWS; y++)
		{
			field[y].resize(COLUMNS);
			cost_table[y].resize(COLUMNS);
			string row;
			cin >> row;
			for (int x{ 0 }; x < COLUMNS; x++)
			{
				cost_table[y][x] = INF;
				if (row[x] == '.')
					field[y][x] = true;
				else
					field[y][x] = false;
			}
		}

		cost_table[sy][sx] = 0;
		cout << bfs() << endl;
	}

	int bfs()
	{
		deque<mytup> q;
		q.push_back(MP(sx, sy));
		int x, y, cost;
		int x_visiting, y_visiting;

		while (!q.empty())
		{
			x = get<0>(q.front());
			y = get<1>(q.front());
			cost = cost_table[y][x];
			q.pop_front();

			if (x == gx && y == gy) return cost;

			cost++;

			for (int i{ 0 }; i < 4; i++)
			{
				x_visiting = x + DX[i];
				y_visiting = y + DY[i];
				if ((0 <= x_visiting < COLUMNS) && (0 <= y_visiting < ROWS)) // within field?
				{
					if (field[y_visiting][x_visiting] && cost < cost_table[y_visiting][x_visiting]) // allowed path ? worth visiting ?
					{
						cost_table[y_visiting][x_visiting] = cost;
						q.push_back(MP(x_visiting, y_visiting));
					}
				}
			}
		}
	}

	C() { cin >> ROWS >> COLUMNS >> sy >> sx >> gy >> gx; sy--; sx--; gx--; gy--; }
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}