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

int a, b, c, k;
int s, t;

int main()
{
	cin >> a >> b >> c >> k >> s >> t;

	if (s + t < k)
	{
		cout << s * a + t * b << endl;
		return 0;
	}

	cout << s * a + t * b - c * (s + t) << endl;
}
