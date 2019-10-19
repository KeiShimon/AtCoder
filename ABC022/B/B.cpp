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

set<int> s;
int n, ans;

int main()
{
	cin >> n;

	REP(i, n)
	{
		int a; cin >> a;
		if (s.count(a))
			++ans;
		else
			s.insert(a);
	}

	cout << ans << endl;
}
