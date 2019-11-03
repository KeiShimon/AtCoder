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
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int> > x;

	REP(i, n)
	{
		int a, b; char _c;
		cin >> a >> _c >> b;

		a = a / 5 * 5;
		b = (b + 4) / 5 * 5;

		if (a % 100 == 60)
			a += 40;
		if (b % 100 == 60)
			b += 40;
		x.push_back(MP(a, 0));
		x.push_back(MP(b, 1));
	}
	sort(ALL(x));

	int cnt = 0;
	REP(i, 2 * n)
	{
		if (cnt == 0)
			cout << setw(4) << setfill('0') << x[i].first << '-';

		if (x[i].second == 0)
		{
			++cnt;
		}
		else
		{
			--cnt;
			if (cnt == 0)
				cout << setw(4) << setfill('0') << x[i].first << endl;
		}
	}

	return 0;
}