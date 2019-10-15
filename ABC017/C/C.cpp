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
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int pts[100002];
int n, m;
int ans, tot;

int main()
{
	cin >> n >> m;

	REP(_i, n)
	{
		int l, r, s;
		cin >> l >> r >> s;
		--l; --r;
		tot += s;
		pts[l] += s;
		pts[r + 1] -= s;
	}

	REP1C(i, m)
		pts[i] += pts[i - 1];

	REP(i, m)
		chmax(ans, tot - pts[i]);

	cout << ans << endl;
}
