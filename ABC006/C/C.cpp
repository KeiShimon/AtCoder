#include <algorithm>
#include <cmath>
#include <deque>
#include <limits.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

using namespace std;

int n, m;

int main()
{
	cin >> n >> m;

	if (m < 2 * n || m > 4 * n)
	{
		cout << "-1 -1 -1" << endl;
		return 0;
	}

	int ans[3]{ n, 0, 0 };
	int d = m - 2 * n;

	ans[2] = d / 2;
	ans[0] -= d / 2;
	d %= 2;

	if (d)
	{
		ans[1]++;
		ans[0]--;
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
