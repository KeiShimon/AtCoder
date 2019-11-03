#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef double dbl;
vector<dbl> vr;
int N, K;

int main()
{
	cin >> N >> K;
	vr.resize(N);

	REP(i, N)
	{
		cin >> vr[i];
	}

	sort(ALL(vr), greater<double>());

	vector<dbl> watch(vr.begin(), vr.begin() + K);
	sort(ALL(watch));
	dbl ans = 0;

	REP(i, K)
	{
		if (ans > watch[i])
			continue;

		ans = (ans + watch[i]) / 2;
	}
	
	cout << setprecision(15) << ans << endl;
}
