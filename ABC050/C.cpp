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

	if (n == 1)
	{
		int a;
		cin >> a;
		if (!a)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}

	vi va(n);
	REP(i, n)
		cin >> va[i];
	sort(ALL(va));


	ll ans = 1;

	if (n & 1)
	{
		if (va[0] != 0 || va[1] == 0)
		{
			cout << 0 << endl;
			return 0;
		}

		int cnt = 1;
		int last = va[1];
		for (int i = 2; i < n; i++)
		{
			if (cnt == 1)
			{
				if (last != va[i])
				{
					cout << 0 << endl;
					return 0;
				}
				else
				{
					++cnt;
					ans = ans * 2 % MOD;
				}
			}
			else if (cnt == 2)
			{
				if (last == va[i])
				{
					cout << 0 << endl;
					return 0;
				}
				cnt = 1;
				last = va[i];
			}
		}
	}

	else
	{
		int cnt = 1;
		int last = va[1];
		REP1O(i, n)
		{
			if (cnt == 1)
			{
				if (last != va[i])
				{
					cout << 0 << endl;
					return 0;
				}
				else
				{
					++cnt;
					ans = ans * 2 % MOD;
				}
			}
			else if (cnt == 2)
			{
				if (last == va[i])
				{
					cout << 0 << endl;
					return 0;
				}
				cnt = 1;
				last = va[i];
			}
		}

	}

	cout << ans << endl;
}
