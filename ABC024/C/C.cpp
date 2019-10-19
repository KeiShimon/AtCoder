#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

int tribe[100][2];
int day[10000][2];
int n, d, k;

int main()
{
	cin >> n >> d >> k;
	REP(i, d) cin >> day[i][0] >> day[i][1];
	REP(i, k) cin >> tribe[i][0] >> tribe[i][1];

	REP(t, k)
	{
		int ans = -1;
		int cur = tribe[t][0], g = tribe[t][1];

		if (cur < g)
		{
			while (cur < g)
			{
				++ans;
				int l = day[ans][0];
				int r = day[ans][1];

				if (l <= cur && cur <= r)
					cur = r;
			}
		}
		else
		{
			while (cur > g)
			{
				++ans;
				int l = day[ans][0];
				int r = day[ans][1];

				if (l <= cur && cur <= r)
					cur = l;
			}
		}

		cout << ans + 1 << endl;
	}
}
