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

int n, a, b;

int main()
{
	int ans = 0;

	cin >> n >> a >> b;

	REP(_i, n)
	{
		string s; int d;
		cin >> s >> d;

		if (d < a)
			d = a;
		if (d > b)
			d = b;

		if (s == "West")
			ans += d;
		else
			ans -= d;
	}
	if (ans > 0)
		cout << "West ";
	else if (ans < 0)
		cout << "East ";

	cout << abs(ans) << endl;
}
