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

ll n, m;
vll x, y;


void init()
{
	cin >> n >> m;
	x.resize(n - 1);
	y.resize(m - 1);

	ll last, tmp;

	cin >> last;
	REP(i, n - 1)
	{
		cin >> tmp;
		x[i] = tmp - last;
		last = tmp;
	}

	cin >> last;
	REP(i, m - 1)
	{
		cin >> tmp;
		y[i] = tmp - last;
		last = tmp;
	}
}

int main()
{
	init();

	ll h = 0, w = 0;

	REP(i, n-1)
	{
		ll tmp = 1;

		tmp = (tmp + i) % MOD;
		tmp = (tmp + (n - 2 - i)) % MOD;
		tmp = (tmp + i * (n - 2 - i) % MOD) % MOD;

		w = (w + x[i] * tmp) % MOD;
	}

	REP(i, m-1)
	{
		ll tmp = 1;

		tmp = (tmp + i) % MOD;
		tmp = (tmp + (m - 2 - i)) % MOD;
		tmp = (tmp + i * (m - 2 - i) % MOD) % MOD;

		h = (h + y[i] * tmp) % MOD;
	}

	ll ans = h * w % MOD;
	
	cout << ans << endl;

}
