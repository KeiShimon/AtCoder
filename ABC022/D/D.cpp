#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef int64_t ll;
typedef double dbl;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll vx[100000], vy[100000];
ll nvx[100000], nvy[100000];
dbl gx, gy, ngx, ngy;
int n;

int main()
{
	cin >> n;

	REP(i, n)
	{
		cin >> vx[i] >> vy[i];
		gx += vx[i]; gy += vy[i];
	}
	REP(i, n)
	{
		cin >> nvx[i] >> nvy[i];
		ngx += nvx[i]; ngy += nvy[i];
	}

	gx /= n; gy /= n;
	ngx /= n; ngy /= n;

	dbl ma = 0, nma = 0;
	REP(i, n)
	{
		dbl dx = abs(gx - vx[i]);
		dbl dy = abs(gy - vy[i]);
		dbl d = dx * dx + dy * dy;
		d = sqrt(d);
		chmax(ma, d);
	}
	REP(i, n)
	{
		dbl dx = abs(ngx - nvx[i]);
		dbl dy = abs(ngy - nvy[i]);
		dbl d = dx * dx + dy * dy;
		d = sqrt(d);
		chmax(nma, d);
	}

	dbl ans = nma / ma;

	cout << setprecision(16) << ans << endl;
}
