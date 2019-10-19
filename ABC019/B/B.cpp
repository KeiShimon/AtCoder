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
#define SZ(x) ((int)(x).size())


int main()
{
	string s; cin >> s;
	ostringstream oss;

	char last = ' ';
	int cnt = 0;

	REP(i, SZ(s))
	{
		if (last == s[i])
			++cnt;
		else
		{
			if (cnt)
				oss << cnt;
			oss << s[i];
			last = s[i];
			cnt = 1;
		}
	}
	oss << cnt;

	cout << oss.str() << endl;
}
