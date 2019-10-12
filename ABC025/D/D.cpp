#include <algorithm>
#include <iostream>
#include <numeric>
#include <string.h>
#include <vector>

#include <bitset>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

const int MOD = 1000000007;

int fix[25], reserved[25];
vector<int> dp(1 << 25, 0);

void init()
{
	memset(fix, -1, sizeof fix);

	REP(p, 25)
	{
		int x; cin >> x;
		if (x)
		{
			reserved[p] = 1;
			fix[x - 1] = p;
		}
	}
}

bool canPut(int cfg, int p)
{
	int row = p / 5;
	int col = p % 5;

	bitset<25> bs(cfg);
	
	if (1 <= row && row <= 3)
	{
		if (bs[p - 5] && !bs[p + 5])
			return false;
		if (bs[p + 5] && !bs[p - 5])
			return false;
	}

	if (1 <= col && col <= 3)
	{
		if (bs[p - 1] && !bs[p + 1])
			return false;
		if (bs[p + 1] && !bs[p - 1])
			return false;
	}

	return true;
}

int main()
{
	init();

	dp[0] = 1;

	REP(cfg, 1 << 25)
	{
		// what you must put next
		int x = 0; 
		for (int tmp = cfg; tmp; tmp >>= 1)
			x += tmp & 1;

		if (~fix[x])
		{
			int p = fix[x];

			if (!(cfg & (1 << p)))
				if (canPut(cfg, p))
					dp[cfg | (1 << p)] = (dp[cfg | (1 << p)] + dp[cfg]) % MOD;

			continue;
		}

		REP(p, 25)
			if (!(cfg & (1 << p)))
				if (!reserved[p])
					if (canPut(cfg, p))
						dp[cfg | (1 << p)] = (dp[cfg | (1 << p)] + dp[cfg]) % MOD;
	}


	cout << dp[(1 << 25) - 1] << endl;
}
