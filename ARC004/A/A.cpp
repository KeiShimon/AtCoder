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

typedef double dbl;

template <class T>
inline double eucladian(T ax, T ay, T bx, T by) { return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }

dbl vx[100], vy[100];
int n;

int main()
{
	cin >> n;

	REP(i, n) cin >> vx[i] >> vy[i];

	dbl ans = 0;
	REP(i, n - 1) for (int j = i + 1; j < n; ++j)
	{
		dbl d = eucladian(vx[i], vy[i], vx[j], vy[j]);
		if (ans < d)
			ans = d;
	}

	cout << setprecision(9) << ans << endl;
}
