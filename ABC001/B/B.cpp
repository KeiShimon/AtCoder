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

int main()
{
	int m;
	cin >> m;

	int vv;
	if (m < 100)
		vv = 0;
	else if (m <= 5000)
		vv = m / 100;
	else if (m <= 30000)
		vv = m / 1000 + 50;
	else if (m <= 70000)
		vv = (m / 1000 - 30) / 5 + 80;
	else
		vv = 89;

	cout << setw(2) << setfill('0') << vv << endl;

}
