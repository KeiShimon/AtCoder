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

typedef int64_t ll;

int main()
{
	string s, t;
	cin >> s >> t;
	s += t;

	ll ans = stoll(s);
	ans <<= 1;
	cout << ans << endl;
}
