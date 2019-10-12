#include <iomanip>
#include <iostream>

using namespace std;

#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

typedef double dbl;

int n, k;
dbl ans;

int main()
{
	cin >> n >> k;

	REP1C(die, n)
	{
		int score = die;
		dbl p = 1;
		while (score < k)
			p /= 2.0, score <<= 1;

		ans += p / n;
	}

	cout << setprecision(12) << ans << endl;
}
