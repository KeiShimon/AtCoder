#include <algorithm>
#include <iostream>
#include <numeric>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef vector<bool> Vb;
typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void init();

int n;
Vi opt, dp;

int main()
{
	init();

	REP(i, n - 1)
		for (int x : opt)
		{
			if (i + x <= n)
				chmin(dp[i + x], dp[i] + 1);
		}
	cout << dp[n] << endl;
}

void init()
{
	cin >> n;
	dp.resize(n + 1);
	REP(i, n + 1)
		dp[i] = i;

	int x = 6;
	while (x <= n)
	{
		opt.PB(x);
		x *= 6;
	}

	x = 9;
	while (x <= n)
	{
		opt.PB(x);
		x *= 9;
	}
}