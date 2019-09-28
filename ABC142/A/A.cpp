#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int n_odd = (n + 1) / 2;
	double ans = (double)n_odd / n;
	cout << setprecision(12) << ans << endl;

}
