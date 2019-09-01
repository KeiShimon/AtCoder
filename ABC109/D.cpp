#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)

using namespace std;

class D {
	int rows, columns;
	vector<vector<bool>> field;
	int n_odd{ 0 };

public:
	D()
	{
		cin >> rows >> columns;
		field.resize(rows);
		int val;
		REP(y, rows)
		{
			field[y].resize(columns, false);
			REP(x, columns)
			{
				cin >> val;
				if (val & 1)
				{
					field[y][x] = true;
					++n_odd;
				}
			}
		}
	}

	void solve()
	{
		int ans_n{ 0 };
		int moves{ 0 };
		int flag{ false };
		int odds_remaining{ n_odd };

		for(int y{0}; y < rows && odds_remaining > 1; y++)
		{
			if (y & 1)
			{
				for (int x{ columns - 1 }; x >= 0 && odds_remaining > 1; x--)
				{
					if (field[y][x])
					{
						if (flag)
						{
							ans_n += ++moves;
							moves = 0;
							flag = false;
							odds_remaining -= 2;
						}
						else
						{
							flag = true;
						}
					}
					else
					{
						if (flag)
						{
							++moves;
						}
					}
				}
			}
			else
			{
				for (int x{ 0 }; x < columns && odds_remaining > 1; x++)
				{
					if (field[y][x])
					{
						if (flag)
						{
							ans_n += ++moves;
							moves = 0;
							flag = false;
							odds_remaining -= 2;
						}
						else
						{
							flag = true;
						}
					}
					else
					{
						if (flag)
						{
							++moves;
						}
					}
				}
			}
		}

		cout << ans_n << endl;
		odds_remaining = n_odd;
		flag = false;
		int last_x{ 0 }, last_y{ 0 };

		for (int y{ 0 }; y < rows && odds_remaining > 1; y++)
		{
			if (y & 1)
			{
				for (int x{ columns - 1 }; x >= 0 && odds_remaining > 1; x--)
				{
					if (flag)
					{
						cout << last_y + 1 << " " << last_x + 1 << " " << y + 1 << " " << x + 1 << endl;
					}
					if (field[y][x])
					{
						if (flag)
							odds_remaining -= 2;
						flag = !flag;
					}
					last_x = x;
					last_y = y;
				}
			}
			else
			{
				for (int x{ 0 }; x < columns && odds_remaining > 1; x++)
				{
					if (flag)
					{
						cout << last_y + 1 << " " << last_x + 1 << " " << y + 1 << " " << x + 1 << endl;
					}
					if (field[y][x])
					{
						if (flag)
							odds_remaining -= 2;
						flag = !flag;
					}
					last_x = x;
					last_y = y;
				}
			}
		}
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}