#include <iomanip>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef double dbl;
typedef vector<double> Vd;

int n;
long long d;
vector<vector<vector<dbl>>> dp(201, vector<vector<dbl>>(101, Vd(101, 0.0)));
dbl prob_1 = 1.0;

int main()
{
	cin >> n >> d;

	if (d == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	int f_2, f_3, f_5;
	f_2 = f_3 = f_5 = 0;
	while (!(d % 2))
		d /= 2, f_2++;
	while (!(d % 3))
		d /= 3, f_3++;
	while (!(d % 5))
		d /= 5, f_5++;

	if (d > 1)
	{
		cout << 0 << endl;
		return 0;
	}

	REP(_i, n)
	{
		vector<vector<vector<dbl>>> newdp(201, vector<vector<dbl>>(101, Vd(101, 0.0)));

		REP(i, 201)
			REP(j, 101)
			REP(k, 101)
			if (dp[i][j][k])
			{
				dp[i][j][k] /= 6;
				newdp[i][j][k] += dp[i][j][k]; // 1
				newdp[i + 1][j][k] += dp[i][j][k]; // 2
				newdp[i][j + 1][k] += dp[i][j][k]; // 3
				newdp[i + 2][j][k] += dp[i][j][k]; // 4
				newdp[i][j][k + 1] += dp[i][j][k]; // 5
				newdp[i + 1][j + 1][k] += dp[i][j][k]; // 6
			}

		prob_1 /= 6.0;
		newdp[1][0][0] += prob_1;
		newdp[0][1][0] += prob_1;
		newdp[2][0][0] += prob_1;
		newdp[0][0][1] += prob_1;
		newdp[1][1][0] += prob_1;

		swap(newdp, dp);
	}

	double ans = 0;

	for (int i = f_2; i < 201; ++i)
		for (int j = f_3; j < 101; ++j)
			for (int k = f_5; k < 101; ++k)
				ans += dp[i][j][k];

	cout << setprecision(9) << ans << endl;
}
