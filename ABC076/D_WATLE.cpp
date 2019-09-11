#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


class D {
	int n;
	int maxt{ 0 };
	vvi grid;
	vvi tr;
	int h, w;
public:
	D()
	{
		cin >> n;
		tr.resize(2, vi(n));

		REP(i, n)
		{
			int x;
			cin >> x;
			maxt += x;
			tr[0][i] = x;
		}

		REP(i, n)
			cin >> tr[1][i];

		h = maxt;
		w = 2 * maxt;

		grid.resize(h, vi(w, 4));


	}

	void drawUp(int st, int sv)
	{
		// cout << "calling drawUp for startT = " << st << " leftVal = " << sv << endl;

		for (int t{ 2 * st }; t < w; t++)
		{
			int val{ sv * 2 + (t - 2 * st) };

			if (val < h && val >= 0)
			{
				if (grid[val][t] == 4)
					grid[val][t] = 3;
				else if (grid[val][t] == 2)
					grid[val][t] = 1;
			}
			for (val += 1; val < h; val++)
			{
				if (!grid[val][t])
					break;
				grid[val][t] = 0;
			}
		}
	}

	void drawDown(int et, int ev)
	{
		// cout << "calling drawDown for endT = " << et << " endVal = " << ev << endl;

		for (int t{ 2 * et - 1}; t >= 0; t--)
		{
			int val{ ev * 2 + (2 * et - 1 - t) };
			
			if (val < h && val >= 0)
			{
				if (grid[val][t] == 4)
					grid[val][t] = 2;
				else if (grid[val][t] == 3)
					grid[val][t] = 1;
			}
			for (val += 1; val < h; val++)
			{
				if (!grid[val][t])
					break;
				grid[val][t] = 0;
			}

		}
	}

	void drawHorizontal(int st, int dur, int val)
	{
		// cout << "calling drawHoriz for startT = " << st << " Val = " << val << ", Dur = " << dur << endl;

		for (int i{ 2 * val }; i < h; i++)
			for (int j{ 2 * st }; j < 2 * (st + dur); j++)
			{
				if (!grid[i][j])
					break;
				grid[i][j] = 0;
			}
	}

	void solve()
	{
		 drawUp(0, 0);
		drawDown(maxt, 0);

		int t{ 0 };
		
		REP(i, n)
		{
			drawDown(t, tr[1][i]);
			drawHorizontal(t, tr[0][i], tr[1][i]);
			t += tr[0][i];
			drawUp(t, tr[1][i]);
		}

		double ans{ 0 };
		int one, half, quarter;
		one = half = quarter = 0;

		REP(i, h)
			REP(j, w)
		{
			if (grid[i][j] == 4)
				++one;
			else if (grid[i][j] == 3 || (grid[i][j] == 2))
				++half;
			else if (grid[i][j] == 1)
				++quarter;
		}

		ans = (double)one + (double)half * 0.5 + (double)quarter * 0.25;

		cout << ans / (double)4 << endl;

	}

};


int main()
{
	D solution;
	solution.solve();

	return 0;
}