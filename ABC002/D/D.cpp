#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int N, M;
bool mat[12][12];

int main()
{
	cin >> N >> M;
	REP(_i, M)
	{
		int x, y; cin >> x >> y; --x; --y;
		mat[x][y] = mat[y][x] = 1;
	}
	REP(i, 12)
		mat[i][i] = 1;

	int ans = 0;
	REP(mask, 1 << 12)
	{
		int cnt = 0;
		bool ok = true;
		for (int x = 0; x < 12 && ok; ++x)
		{
			if (!(mask & (1 << x)))
				continue;

			++cnt;
				
			for (int y = 0; y < 12 && ok; ++y)
			{
				if ((mask & (1 << y)) && !mat[x][y])
					ok = false;
			}
		}

		if (ok)
			chmax(ans, cnt);
	}

	cout << ans << endl;
}
