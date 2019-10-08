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

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

int n, k;
int g[5][5];

int dfs(int i, int j, int x)
{

	x ^= g[i][j];

	if (i == n - 1)
		return x;

	REP(j_new, k)
	{
		if (!dfs(i + 1, j_new, x))
			return 0;
	}

	return 1;
}

int main()
{
	cin >> n >> k;

	REP(i, n)
		REP(j, k)
		cin >> g[i][j];

	REP(j, k)
	{
		if (!dfs(0, j, 0))
		{
			cout << "Found" << endl;
			return 0;
		}
	}

	cout << "Nothing" << endl;
}

