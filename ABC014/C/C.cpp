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
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

const int MAX_COL = 1000000;

int n;
int s[MAX_COL + 3];

int main()
{
	cin >> n;

	REP(_i, n)
	{
		int l, r;
		cin >> l >> r;
		s[l]++;
		s[r + 1]--;
	}

	int ans = s[0];
	REP1C(i, MAX_COL)
	{
		s[i] += s[i - 1];
		chmax(ans, s[i]);
	}

	cout << ans << endl;
}
