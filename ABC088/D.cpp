#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#include <tuple>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

typedef tuple<int, int, int> tupiii;

class D {
	int rows, cols;
	vector<string> field;
	vector<vector<int>> dist;
	int black{ 0 };
public:
	D()
	{
		cin >> rows >> cols;
		field.resize(rows);
		dist.resize(rows, vector<int>(cols, INTMAX));
		REP(y, rows)
		{
			cin >> field[y];
			REP(x, cols)
				if (field[y][x] == '#')
					++black;
		}
	}

	int bfs()
	{
		deque<tupiii> q{ make_tuple(0, 0, 1) };

		int x, y, d;
		while (!q.empty())
		{
			y = get<0>(q.front());
			x = get<1>(q.front());
			d = get<2>(q.front());
			q.pop_front();

			if (y == rows - 1 && x == cols - 1)
				return d;

			REP(i, 4)
			{
				if (0 <= x + dx[i] && x + dx[i] < cols && 0 <= y + dy[i] && y + dy[i] < rows)
					if (field[y + dy[i]][x + dx[i]] == '.' && dist[y + dy[i]][x + dx[i]] == INTMAX)
					{
						q.emplace_back(make_tuple(y + dy[i], x + dx[i], d + 1));
						dist[y + dy[i]][x + dx[i]] = d + 1;
					}
			}

		}

		return -1;

	}

	void solve()
	{
		int d{ bfs() };

		if (d == -1)
		{
			cout << -1 << endl;
			return;
		}

		else
			cout << (rows * cols - black - d) << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}