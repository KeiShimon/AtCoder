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

int main()
{
	int ans = 0;
	REP(i, 3)
	{
		int a, b;
		cin >> a >> b;
		ans += a * b / 10;
	}

	cout << ans << endl;
}
