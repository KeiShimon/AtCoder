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

int n, x;
int a[21];

int main()
{
	cin >> n >> x;
	REP(i, n) cin >> a[i];

	int ans = 0;
	REP(bit, n)
		if (x & (1 << bit))
			ans += a[bit];

	cout << ans << endl;
}
