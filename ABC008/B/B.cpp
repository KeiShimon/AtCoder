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
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++)

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

map<string, int> m;

int main()
{
	int n; cin >> n;
	REP(_i, n)
	{
		string s;
		cin >> s;
		m[s]++;
	}

	string ans;
	int most= 0;

	REPIT(it, m)
	{
		if (chmax(most, it->second))
			ans = it->first;
	}

	cout << ans << endl;
}
