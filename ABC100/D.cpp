#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>
#include <deque>

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
	int n, m;
	vector<vector<ll>> cakes;
	vector<ll> val;
public:
	D()
	{
		cin >> n >> m;

		cakes.resize(n, vector<ll>(3));
		val.resize(n);

		REP(i, n)
			REP(j, 3)
			cin >> cakes[i][j];

	}
	void solve()
	{
		ll ans{ 0 };
		for (int bit{ 0 }; bit < 8; bit++)
		{
			int sign[3];
			sign[0] = (bit & 0b100) ? 1 : -1;
			sign[1] = (bit & 0b010) ? 1 : -1;
			sign[2] = (bit & 0b001) ? 1 : -1;

			REP(i, n)
			{
				val[i] = 0;
				REP(j, 3)
					val[i] += cakes[i][j] * sign[j];
			}

			sort(ALL(val), greater<ll>());
			ll tmpsum{ accumulate(val.begin(), val.begin() + m, 0ll) };
			chmax(ans, tmpsum);

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