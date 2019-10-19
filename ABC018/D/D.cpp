#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int n_a, n_b, p, q, r;
int g[18][18];

int main()
{
	cin >> n_a >> n_b >> p >> q >> r;

	REP(_i, r)
	{
		int x, y, z;
		cin >> x >> y >> z;
		--x; --y;
		g[y][x] = z;
	}

	int ans = 0;

	REP(mask, 1 << n_a)
	{
		int cnt = 0;
		for (int tmp = mask; tmp; tmp >>= 1)
			cnt += tmp & 1;

		if (cnt != p)
			continue;

		Vi score(n_b, 0);
		REP(i, n_b)
		{
			int tmp = 0;
			REP(bit, n_a)
				if (mask & (1 << bit))
					tmp += g[i][bit];
			score[i] = tmp;
		}
		sort(ALL(score), greater<>());

		int res = accumulate(score.begin(), score.begin() + q, 0);
		chmax(ans, res);
	}

	cout << ans << endl;
}
