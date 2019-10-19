#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef vector<string> Vs;

const int MAX_C = 505;
int h, w, k;
int U[MAX_C][MAX_C], D[MAX_C][MAX_C];
Vs grid;

int main()
{
	cin >> h >> w >> k;
	REP(_i, h)
	{
		string s; cin >> s;
		grid.push_back(s);
	}

	REP(j, w)
		REP(i, h - 1)
	{
		if (grid[i][j] == 'o')
			U[i + 1][j] = U[i][j] + 1;
		else
			U[i + 1][j] = 0;

		if (grid[h - 1 - i][j] == 'o')
			D[h - 2 - i][j] = D[h - 1 - i][j] + 1;
		else
			D[h - 2 - i][j] = 0;
	}

	int ans = 0;
	REP(i, h) REP(j, w)
	{
		if (j < k - 1 || j > w - k)
			continue;

		bool flag = true;
		for (int dx = -k + 1; dx < k; ++dx)
		{
			if (grid[i][j + dx] == 'x')
			{
				flag = false; break;
			}
			if (U[i][j + dx] < (k - 1 - abs(dx)) || D[i][j + dx] < (k - 1 - abs(dx)))
			{
				flag = false; break;
			}
		}

		ans += flag;
	}

	cout << ans << endl;
}
