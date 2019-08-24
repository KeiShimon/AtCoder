#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class C {
	int N;
	vector<int> dp;
	int options[12]{ 1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049 };
	int n_options{ 12 };
	int MAX{ 100005 };

public:
	void solve()
	{
		cin >> N;

		for (int i{ 0 }; i < N; i++)
		{
			for (int j{ 0 }; j < n_options; j++)
			{
				if ((i + options[j]) < MAX)
				{
					dp[i + options[j]] = min(dp[i + options[j]], dp[i] + 1);
				}
			}
		}

		cout << dp[N] << endl;

	}

	C()
	{
		dp.resize(MAX);
		for (int i{ 0 }; i < MAX; i++) dp[i] = 99999;
		dp[0] = 0;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}