#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int dx[4]{ -1, 1, 0, 0 };
const int dy[4]{ 0, 0, 1, -1 };

class C {
	int ROWS, COLUMNS;
	vector<string> picture;

public:
	void solve()
	{
		for (int y{ 0 }; y < ROWS; y++)
		{
			for (int x{ 0 }; x < COLUMNS; x++)
			{
				if ((picture[y][x] == '#') && !dfs(x, y, true))
				{
					cout << "No" << endl;
					return;
				}
			}
		}
		cout << "Yes" << endl;
	}
	
	bool dfs(const int& x, const int& y, bool isFirstElem)
	{
		if (picture[y][x] == '.')
			return false;

		picture[y][x] = '.';

		if (!isFirstElem)
		{
			int x_visiting, y_visiting;
			for (int i{ 0 }; i < 4; i++)
			{
				x_visiting = x + dx[i];
				y_visiting = y + dy[i];
				if ((0 <= x_visiting && x_visiting < COLUMNS) && (0 <= y_visiting && y_visiting < ROWS) && picture[y_visiting][x_visiting] == '#')
					dfs(x_visiting, y_visiting, false);
			}

			return true;
		}
		else
		{
			bool flag{ false };
			int x_visiting, y_visiting;

			for (int i{ 0 }; i < 4; i++)
			{
				x_visiting = x + dx[i];
				y_visiting = y + dy[i];
				if ((0 <= x_visiting && x_visiting < COLUMNS) && (0 <= y_visiting && y_visiting < ROWS))
					flag |= dfs(x_visiting, y_visiting, false);
			}

			return flag;
		}
	}


	C()
	{
		cin >> ROWS >> COLUMNS;
		picture.resize(ROWS);

		for (int y{ 0 }; y < ROWS; y++)
		{
			cin >> picture[y];
		}
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}