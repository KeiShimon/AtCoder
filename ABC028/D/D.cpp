#include <iomanip>
#include <iostream>

using namespace std;

double n, k;

int main()
{
	cin >> n >> k;

	double cnt = 1;
	cnt += 6 * (k - 1) * (n - k);
	cnt += 3 * (n - 1);

	double ans = cnt / (n * n * n);
	cout << setprecision(15) << ans << endl;
}
