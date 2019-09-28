#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef int64_t ll;
typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 2e8;

int n, m;
Vi va, open, dp;

void init()
{
	cin >> n >> m;
	va.resize(m);
	open.resize(m);
	dp.resize(1 << n, inf);

	REP(i, m)
	{
		int a, b; cin >> a >> b;
		va[i] = a;

		int open_mask = 0;
		REP(_i, b)
		{
			int chest; cin >> chest;
			open_mask |= 1 << (chest - 1);
		}

		chmin(dp[open_mask], a);
	}
}

int main()
{
	init();

	int target = (1 << n) - 1;

	REP(i, target)
	{
		if (dp[i] == inf)
			continue;

		for (int j = i + 1; j <= target; ++j)
			chmin(dp[i | j], dp[i] + dp[j]);
	}


	if (dp[target] == inf)
		cout << -1 << endl;
	else
		cout << dp[target] << endl;

}
