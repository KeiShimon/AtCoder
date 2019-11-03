#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef vector<int> Vi;

int n;
Vi vc, n_divisors;

void init()
{
	cin >> n;
	vc.resize(n);
	REP(i, n) cin >> vc[i];
	sort(ALL(vc));
}

void countDivisors()
{
	n_divisors.resize(n, 0);

	REP(i, n)
		REP(j, n)
		if (!(vc[i] % vc[j]) && i != j)
			++n_divisors[i];
}

int main()
{
	init();
	countDivisors();

	double ans = 0;
	REP(i, n)
	{
		int x = 1 + n_divisors[i] / 2;
		double p = (double)x / (n_divisors[i] + 1);

		ans += p;
	}

	cout << setprecision(9) << ans << endl;
}
