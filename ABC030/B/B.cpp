#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	h %= 12;

	double d_h = 30 * h + (double)m / 2;
	double d_m = 6 * m;

	double ans = max(d_m, d_h) - min(d_m, d_h);

	if (ans > 180) ans = 360 - ans;

	cout << setprecision(8) << ans << endl;
}
