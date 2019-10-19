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
typedef vector<int> Vi;

int n, t;
Vi visiter;

int main()
{
	cin >> n >> t;
	visiter.resize(n);
	REP(i, n) cin >> visiter[i];

	int now = visiter[0];
	int ans = t;
	REP(i, n)
	{
		if (visiter[i] > now + t)
			ans += t;
		else
			ans += visiter[i] - now;
		now = visiter[i];
	}

	cout << ans << endl;
}
