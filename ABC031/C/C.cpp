#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int inf = 1 << 30;

int n;
Vi va;

int main()
{
	cin >> n;
	va.resize(n);
	REP(i, n) cin >> va[i];

	int ans = -inf;

	REP(a, n)
	{
		int score_a;
		int max_b = -inf;

		REP(b, n)
		{
			if (a == b)
				continue;

			int suma = 0, sumb = 0;
			int p = 1;
			for (int i = min(a, b); i <= max(a, b); ++i)
			{
				if (p)
					suma += va[i];
				else
					sumb += va[i];
				p ^= 1;
			}

			if (chmax(max_b, sumb))
				score_a = suma;
		}

		chmax(ans, score_a);
	}

	cout << ans << endl;
}
