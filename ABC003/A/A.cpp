#include <iomanip>
#include <iostream>

using namespace std;

int N;

int main()
{
	double ans = 0;
	int N;
	cin >> N;
	for (int x = 1; x <= N; ++x)
		ans += (double)10000 * x / N;

	cout << setprecision(15) << ans << endl;
}
