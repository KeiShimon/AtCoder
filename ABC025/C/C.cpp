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
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

map<string, int> memo;
int b[2][3], c[3][2], tot;

int calc(string s)
{
	int ret = 0;

	REP(i, 6)
		if (s[i] == s[i + 3])
			ret += b[i / 3][i % 3];

	REP(i, 3) REP(j, 2)
		if (s[i * 3 + j] == s[i * 3 + j + 1])
			ret += c[i][j];

	return ret;
}

int rec(string s, int p)
{
	if (memo.count(s))
		return memo[s];

	if (s.find('0') == string::npos)
		return memo[s] = calc(s);

	int ret;
	if (p == 1)
		ret = 0;
	else
		ret = 1 << 28;

	REP(i, 9)
	{
		if (s[i] == '0')
		{
			s[i] += p;

			if (p == 1)
				chmax(ret, rec(s, 3 - p));
			else
				chmin(ret, rec(s, 3 - p));
			
			s[i] -= p;
		}
	}

	return memo[s] = ret;
}

int main()
{
	REP(i, 2) REP(j, 3) cin >> b[i][j], tot += b[i][j];
	REP(i, 3) REP(j, 2) cin >> c[i][j], tot += c[i][j];

	int ans = rec("000000000", 1);

	cout << ans << endl;
	cout << tot - ans << endl;
}
