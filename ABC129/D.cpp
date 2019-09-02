#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i > 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t int64;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;

class D {
	int rows, columns;
	vector<vector<int>> left, right, up, down;
	vector<string> field;
public:
	D()
	{
		cin >> rows >> columns;

		left.resize(rows, vector<int>(columns, 0));
		right.resize(rows, vector<int>(columns, 0));
		up.resize(rows, vector<int>(columns, 0));
		down.resize(rows, vector<int>(columns, 0));

		field.resize(rows);
		REP(y, rows)
			cin >> field[y];
	}

	void set()
	{
		REP(y, rows)
		{
			int count_left{ 0 }, count_right{ 0 };
			REP(i, columns)
			{
				left[y][i] = count_left;
				right[y][columns - i - 1] = count_right;

				if (field[y][i] == '.')
					count_left++;
				else
					count_left = 0;

				if (field[y][columns - i - 1] == '.')
					count_right++;
				else
					count_right = 0;
			}
		}

		REP(x, columns)
		{
			int count_up{ 0 }, count_down{ 0 };
			REP(i, rows)
			{
				up[i][x] = count_up;
				down[rows - i - 1][x] = count_down;

				if (field[i][x] == '.')
					count_up++;
				else
					count_up = 0;

				if (field[rows - i - 1][x] == '.')
					count_down++;
				else
					count_down = 0;
			}
		}

	}

	void solve()
	{
		set();

		int64 ans{ 0 };
		REP(y, rows)
			REP(x, columns)
			if (field[y][x] == '.')
				chmax(ans, (int64)1 + left[y][x] + right[y][x] + up[y][x] + down[y][x]);

		cout << ans << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}