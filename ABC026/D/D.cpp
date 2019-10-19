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

typedef double dbl;
const int inf = 1 << 28;
const dbl pi = atan2(0, -1);

dbl a, b, c;

int main()
{
	cin >> a >> b >> c;

	dbl ok = 0, ng = inf;

	REP(_i, 100)
	{
		dbl t = (ng + ok) / 2;
		
		dbl f = a * t + b * sin(c * pi * t);

		if (f > 100)
			ng = t;
		else
			ok = t;
	}

	cout << setprecision(15) << ok << endl;
}
