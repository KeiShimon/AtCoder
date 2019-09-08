#include <algorithm>
#include <cmath>
#include <deque>
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

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;

class D {
	int n, c;
	vector<vector<int>> d;
	vector<vector<int>> info;
public:
	D()
	{
		cin >> n >> c;

		d.resize(c, vector<int>(c));
		REP(i, c)
			REP(j, c)
			cin >> d[i][j];

		info.resize(3, vector<int>(c, 0));
		int inp;
		REP(i, n)
			REP(j, n)
		{
			cin >> inp;
			++info[(i + j) % 3][--inp];
		}
	}

	void debug()
	{
		REP(i, 3)
		{
			REP(j, c)
				cout << info[i][j] << " ";
			cout << endl;
		}
	}

	void solve()
	{
		ll ans{ 9223372036854775807 };

		REP(col_0, c)
		{
			ll val_0{ 0 };
			REP(i, c)
				val_0 += (ll)info[0][i] * d[i][col_0];

			REP(col_1, c)
			{
				if (col_1 == col_0)
					continue;

				ll val_1{ 0 };
				REP(i, c)
					val_1 += (ll)info[1][i] * d[i][col_1];

				REP(col_2, c)
				{
					if (col_2 == col_0 || col_2 == col_1)
						continue;

					ll val_2{ 0 };
					REP(i, c)
						val_2 += (ll)info[2][i] * d[i][col_2];

					chmin(ans, val_0 + val_1 + val_2);

				}
			}
		}

		cout << ans << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}