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

using namespace std;

typedef int64_t ll;

const ll target = 2e12;
ll a, k;

int main()
{
	cin >> a >> k;

	if (!k)
	{
		cout << target - a << endl;
		return 0;
	}

	ll ans = 0;
	while (a < target)
	{
		a = a + 1 + k * a;
		++ans;
	}

	cout << ans << endl;

}
