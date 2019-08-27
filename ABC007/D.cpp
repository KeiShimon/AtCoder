#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <string.h>

using namespace std;

const int MAX_DIGITS{ 19 };

class D {
	int64_t A, B;

public:
	void solve()
	{
		A--;
		int64_t ans = (solve_helper(B, to_string(B).size()) - solve_helper(A, to_string(A).size()));
		cout << ans << endl;
	}

	int64_t solve_helper(const int64_t& target, const int& digits)
	{
		// dp[ Œˆ‚ß‚½Œ…” ][ –¢–žƒtƒ‰ƒO ][ 4 ‚Ü‚½‚Í 9 ‚ðŠÜ‚Þ‚© ]
		int64_t dp[MAX_DIGITS + 1][2][2];
		memset(dp, 0, sizeof dp);
		dp[0][0][0] = 1;

		for (int d{ 0 }; d < digits; d++)
		{
			int original_digit = target / (int64_t)pow(10, digits - d - 1) % 10;

			for (int isLess{ 0 }; isLess <= 1; isLess++)
			{
				for (int containsFourOrNine{ 0 }; containsFourOrNine <= 1; containsFourOrNine++)
				{
					for (int k{ 0 }; k <= (isLess ? 9 : original_digit); k++)
					{
						dp[d + 1][isLess || (k < original_digit)][(k == 4) || (k == 9) || containsFourOrNine] += dp[d][isLess][containsFourOrNine];
					}
				}
			}
		}

		return dp[digits][0][1] + dp[digits][1][1];

	}

	D() { cin >> A >> B; }
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}