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
#define ALL(x) (x).begin(),(x).end()

typedef double dbl;
typedef vector<int> Vi;


dbl pi = atan2(0, -1);
int n;
Vi r;

int main()
{
	cin >> n;
	int ans = 0;

	REP(i, n)
	{
		int x;
		cin >> x;
		r.push_back(x);
	}

	sort(ALL(r), greater<>());

	REP(i, n)
	{
		if (!(i & 1))
			ans += r[i] * r[i];
		else
			ans -= r[i] * r[i];
	}

	cout << setprecision(15) << pi * ans << endl;
}
