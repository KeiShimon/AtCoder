#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const int MOD = 1000000007;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }



int main()
{
	ll h, w; cin >> h >> w;
	ll al = h * w;

	if (!(h % 3) || !(w % 3))
	{
		cout << 0 << endl;
		return 0;
	}

	ll ans = al;

	REP1O(y, h)
	{
		ll a = w * y;
		ll b, c, ma , mi;

		b = (h - y) / 2 * w;
		c = al - a - b;

		ma = max(a, max(b, c));
		mi = min(c, min(a, b));

		chmin(ans, ma - mi);

		b = (h - y) * (w / 2);
		c = al - a - b;

		ma = max(a, max(b, c));
		mi = min(c, min(a, b));

		chmin(ans, ma - mi);

	}

	REP1O(x, w)
	{
		ll a = h * x;
		ll b, c, ma, mi;

		b = (w - x) / 2 * h;
		c = al - a - b;

		ma = max(a, max(b, c));
		mi = min(c, min(a, b));

		chmin(ans, ma - mi);

		b = (w - x) * (h / 2);
		c = al - a - b;

		ma = max(a, max(b, c));
		mi = min(c, min(a, b));

		chmin(ans, ma - mi);
	}

	cout << ans << endl;
}
