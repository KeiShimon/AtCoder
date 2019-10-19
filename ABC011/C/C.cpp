#include <iostream>
#include <string.h>

using namespace std;

#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

const int inf = 1 << 28;

int N, ng[3];
int dp[305];

int main()
{
	REPC(i, 300) dp[i] = inf;
	cin >> N >> ng[0] >> ng[1] >> ng[2];
	dp[0] = 0;

	REP1C(i, 300)
	{
		if (i == ng[0] || i == ng[1] || i == ng[2])
		{
			dp[i] = inf;
			continue;
		}

		if (i - 1 >= 0)
			chmin(dp[i], dp[i - 1] + 1);
		if (i - 2 >= 0)
			chmin(dp[i], dp[i - 2] + 1);
		if (i - 3 >= 0)
			chmin(dp[i], dp[i - 3] + 1);
	}

	if (dp[N] <= 100)
		YES();
	else
		NO();
}
