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
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t int64;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


class D {
	int n, m, q;
	static const int MAX_M{ 200001 };
	static const int MAX_N{ 501 };

public:
	D()
	{
		cin >> n >> m >> q;
	}

	// O(n^2 + qn)
	void solve_cumulative()
	{
		int l, r;
		int x[MAX_N][MAX_N], cum[MAX_N][MAX_N];
		memset(cum, 0, sizeof cum);
		memset(x, 0, sizeof x);


		REP(i, m)
		{
			cin >> l >> r;
			++x[l][r];
		}

		// O(n^2)
		REP(i, n)
			REP(j, n)
		{
			cum[i + 1][j + 1] = cum[i + 1][j] + x[i + 1][j + 1];
		}

		// O(qn)
		REP(i, q) // q loops
		{
			cin >> l >> r;
			int sum{ 0 };

			for (int j{ l }; j <= r; j++) // n loops
				sum += cum[j][r] - cum[j][l - 1];

			cout << sum << endl;
		}

		// end solution solve_cumulative
	}

	// O(n^2 + q)
	void solve_2Dcumulative()
	{
		int l, r;
		int cum[MAX_N][MAX_N];
		memset(cum, 0, sizeof cum);

		REP(i, m)
		{
			cin >> l >> r;
			++cum[l][r];
		}

		// O(n^2)
		REP(i, n)
			REP(j, n)
			cum[i + 1][j + 1] += cum[i + 1][j];

		// O(n^2)
		REP(i, n)
			REP(j, n)
			cum[i + 1][j + 1] += cum[i][j + 1];

		// O(q)
		REP(i, q)
		{
			cin >> l >> r;

			int ans{ cum[r][r] + cum[l - 1][l - 1] - cum[l - 1][r] - cum[r][l - 1] };

			cout << ans << endl;
		}

		// end solution solve_2Dcumulative
	}

	void solve()
	{
		solve_2Dcumulative();
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}