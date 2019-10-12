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

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int n, s, longest;

int main()
{
	cin >> n;

	REP(_i, n)
	{
		int x;
		cin >> x;
		chmax(longest, x);
		s += x;
	}

	cout << s << endl;

	if (longest * 2 <= s)
		cout << 0 << endl;
	else
		cout << 2 * longest - s << endl;

}
