#include <iomanip>
#include <iostream>
#include <string.h>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef double dbl;

const int MAX = 300;

void init();
double rec(int i, int j, int k);

double dp[301][301][301];
int n, c[4];

int main()
{
	init();

	cout << setprecision(15) << rec(c[1], c[2], c[3]) << endl;
}

void init()
{
	memset(dp, -1, sizeof dp);
	memset(c, 0, sizeof c);

	cin >> n;
	REP(_i, n)
	{
		int x; cin >> x;
		c[x]++;
	}
}

double rec(int i, int j, int k)
{
	if (dp[i][j][k] >= 0)
		return dp[i][j][k];

	int s = i + j + k;
	if (!s)
		return dp[i][j][k] = 0.0;

	double ret = 0.0;
	
	if (i > 0) ret += rec(i - 1, j, k) * ((dbl)i / s);
	if (j > 0) ret += rec(i + 1, j - 1, k) * ((dbl)j / s);
	if (k > 0) ret += rec(i, j + 1, k - 1) * ((dbl)k / s);

	ret += ((dbl)n / s);

	return dp[i][j][k] = ret;

}