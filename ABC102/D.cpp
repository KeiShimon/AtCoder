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

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class D {
	int n;
	vector<int> a;
	vector<ll> cum;

public:
	D()
	{
		cin >> n;
		a.resize(n);
		cum.resize(n, 0);

		int ai;
		cin >> ai;
		a[0] = cum[0] = ai;

		REP(i, n - 1)
		{
			cin >> ai;
			a[i + 1] = ai;
			cum[i + 1] = cum[i] + ai;
		}
	}

	void solve()
	{
		ll ans{ 9223372036854775807 };
		ll tmp[4];

		int first{ 0 };
		int second{ 1 };
		int third{ 2 };
		ll mindiff;

		for (; second <= n - 3; second++)
		{

			mindiff = 9223372036854775807;
			for (int tmpfirst{ first }; tmpfirst < second; tmpfirst++)
			{
				ll left{ cum[tmpfirst] };
				ll right{ cum[second] - cum[tmpfirst] };

				if (chmin(mindiff, abs(left - right)))
				{
					tmp[0] = left;
					tmp[1] = right;
					first = tmpfirst;
				}
				else
					if (left > right)
						break;

			}

			mindiff = 9223372036854775807;
			for (int tmpthird{ third }; tmpthird <= n - 2; tmpthird++)
			{
				ll left{ cum[tmpthird] - cum[second] };
				ll right{ cum[n - 1] - cum[tmpthird] };

				if (chmin(mindiff, abs(left - right)))
				{
					tmp[2] = left;
					tmp[3] = right;
					third = tmpthird;
				}
				else
					if (left > right)
						break;
			}

			ll ma{ tmp[0] };
			chmax(ma, tmp[1]); chmax(ma, tmp[2]); chmax(ma, tmp[3]);
			ll mi{ tmp[0] };
			chmin(mi, tmp[1]); chmin(mi, tmp[2]); chmin(mi, tmp[3]);
			
			chmin(ans, abs(ma - mi));
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