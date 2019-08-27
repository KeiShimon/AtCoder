#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef int64_t LL;

template <class T>
inline void chmax(T& a, const T& b) { if (a < b) a = b; }

const int MAX_DIGIT{ 40 };

class D {
	LL N, K;
	vector<LL> A;

public:
	void solve()
	{
		LL mask{ 0 };
		LL dp[MAX_DIGIT + 1][2];
		memset(dp, -1, sizeof dp);
		dp[0][0] = 0;
		
		for (int i{ 0 }; i < N; i++)
			cin >> A[i];

		for (int d{ 0 }; d < MAX_DIGIT; d++)
		{
			mask = (1LL << (MAX_DIGIT - d - 1));
			LL set1{ 0 };
			LL set0{ 0 };

			for (int i{ 0 }; i < N; i++)
			{
				if (A[i] & mask)
					++set0;
			}
			set1 = N - set0;

			set1 *= mask;
			set0 *= mask;

			// smaller -> smaller
			if (dp[d][1] != -1)
			{
				chmax(dp[d + 1][1], dp[d][1] + max(set1, set0));
			}

			// exaxt -> smaller
			if (dp[d][0] != -1 && (K & mask))
			{
				chmax(dp[d + 1][1], dp[d][0] + set0);
			}

			// exaxt -> exaxt
			if (dp[d][0] != -1)
			{
				chmax(dp[d + 1][0], dp[d][0] + ((K & mask) ? set1 : set0));
			}

		}

		cout << max(dp[MAX_DIGIT][0], dp[MAX_DIGIT][1]) << endl;
		
	}

	D() { cin >> N >> K; A.resize(N); }
};

int main()
{
	D solution;
	solution.solve();

	return 0;
}