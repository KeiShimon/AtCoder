#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;
typedef double dbl;
typedef vector<dbl> Vd;

const int MAX_N = 2000;
const dbl eps = 1e-10;
const dbl pi = acos(-1);
int vx[MAX_N], vy[MAX_N];
int N;
ll R, O, A;

int main()
{
	cin >> N;
	REP(i, N) cin >> vx[i] >> vy[i];

	REP(i, N)
	{
		Vd va; va.reserve(N - 1);

		REP(j, N)
			if (i != j)
				va.push_back(atan2(vy[j] - vy[i], vx[j] - vx[i]));
		sort(ALL(va));

		REP(j, N - 1)
			va.push_back(va[j] + pi * 2);

		REP(j, N - 1)
		{
			int x = lower_bound(ALL(va), va[j] + pi / 2 - eps) - va.begin();
			int y = upper_bound(ALL(va), va[j] + pi / 2 + eps) - va.begin();
			int z = lower_bound(ALL(va), va[j] + pi - eps) - va.begin();

			R += y - x;
			O += z - y;
		}
	}

	ll tot = (ll)N * ((ll)N - 1) * ((ll)N - 2) / 6;
	A = tot - R - O;
	cout << A << " " << R << " " << O << endl;
}
