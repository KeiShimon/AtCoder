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
	int n;
	cin >> n;
	ll a, b;
	cin >> a >> b;

	REP(i, n - 1)
	{
		ll x, y;
		cin >> x >> y;

		ll ta1, ta2, tb1, tb2;

		ta1 = (a + (x - 1)) / x * x;
		tb1 = ta1 / x * y;

		tb2 = (b + (y - 1)) / y * y;
		ta2 = tb2 / y * x;

		//cout << ta1 << " " << tb1 << endl;
		//cout << ta2 << " " << tb2 << endl;

		if (tb1 < b)
		{
			b = tb2; a = ta2;
		}
		else if (ta2 < a)
		{
			b = tb1; a = ta1;
		}
		else if (ta1 + tb1 < ta2 + tb2)
		{
			b = tb1; a = ta1;
		}
		else
		{
			b = tb2; a = ta2;
		}

	}

	cout << a + b << endl;

}
