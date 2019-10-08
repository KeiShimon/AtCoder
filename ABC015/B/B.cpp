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

int main()
{
	int n;
	cin >> n;

	int denom = 0;
	double numer = 0;

	REP(_i, n)
	{
		int a; cin >> a;
		numer += a;

		if (a)
			++denom;
	}

	cout << ceil(numer / denom) << endl;
}
