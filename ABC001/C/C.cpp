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

const int inf = 1 << 28;

const string s[] = { "N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N" };
const int a[] = { 25,155,335,545,795,1075,1385,1715,2075,2445,2845,3265, inf / 10 };

int main()
{
	int deg, dis;
	cin >> deg >> dis;

	int i = 0;
	while (deg * 10 >= 1125 + 2250 * i)
		++i;

	int j = 0;
	while (dis * 10 >= a[j] * 6)
		++j;

	if (j == 0)
		cout << "C " << j << endl;
	else
		cout << s[i] << ' ' << j << endl;

	return 0;
}
