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

#define ALL(x) (x).begin(),(x).end()


int main()
{
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(ALL(a));
	cout << a[1] << endl;
}
