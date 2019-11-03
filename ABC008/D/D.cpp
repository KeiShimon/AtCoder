#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

vector<int> vx, vy, vxs, vys, vxc, vyc;
int w, h;
int n;
int dp[32][32][32][32];

void init()
{
	ios::sync_with_stdio(false);
	cin.tie();

	cin >> w >> h >> n;
	vx.resize(n);
	vy.resize(n);
	REP(i, n) cin >> vx[i] >> vy[i];

	vxs = vx;
	vys = vy;
	vxs.push_back(0); vxs.push_back(w + 1);
	vys.push_back(0); vys.push_back(h + 1);
	sort(ALL(vxs)); sort(ALL(vys));

	vxc.reserve(n + 2);
	vyc.reserve(n + 2);
	REP(i, n)
	{
		int i_x = lower_bound(ALL(vxs), vx[i]) - vxs.begin();
		int i_y = lower_bound(ALL(vys), vy[i]) - vys.begin();
		vxc.push_back(i_x);
		vyc.push_back(i_y);
	}

	memset(dp, -1, sizeof dp);
	dp[0][0][0][0] = 0;
}

int recursiveDPSolver(int l, int r, int d, int u)
{
	int ret;
	if ((ret = dp[l][r][d][u]) != -1)
		return ret;

	ret = 0;
	REP(i, n)
	{
		int xc = vxc[i], yc = vyc[i];
		if (l < xc && xc < r && d < yc && yc < u)
		{
			int tmp = 0;
			tmp += recursiveDPSolver(l, xc, d, yc);
			tmp += recursiveDPSolver(xc, r, d, yc);
			tmp += recursiveDPSolver(l, xc, yc, u);
			tmp += recursiveDPSolver(xc, r, yc, u);
			tmp += vxs[r] - vxs[l] + vys[u] - vys[d] - 3;

			if (ret < tmp) ret = tmp;
		}
	}

	dp[l][r][d][u] = ret;
	return ret;
}

int main()
{
	init();
	cout << recursiveDPSolver(0, n + 1, 0, n + 1) << endl;
}
