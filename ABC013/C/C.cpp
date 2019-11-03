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

#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)

typedef int64_t ll;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int n;
ll h, a, b, c, d, e;

int main()
{
	cin >> n >> h;
	cin >> a >> b >> c >> d >> e;

	ll ans = 1LL << 61;

	REPC(x, n)
	{
		int y = ((e * (n - x) - h - b * x)) / (d + e);
		chmax(y, 0);

		if (x + y > n)
			continue;

		if (h + b * x + d * y - e * (n - x - y) <= 0)
			++y;

		if (x + y <= n)
			chmin(ans, a * x + c * y);
	}

	cout << ans << endl;
}
