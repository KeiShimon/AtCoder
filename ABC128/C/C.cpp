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


vector<vector<bool>> connect;
vector<int> vp;
int n, m;

void init()
{
	cin >> n >> m;

	connect.resize(m);
	vp.resize(m);

	REP(i, m)
	{
		int k; cin >> k;
		connect[i].resize(n, false);

		REP(_i, k)
		{
			int s; cin >> s; s--;
			connect[i][s] = true;
		}
	}

	REP(i, m)
		cin >> vp[i];

}

bool check(int mask, int p)
{
	int cnt = 0;

	for (int bit = 0; bit < n; bit++)
	{
		if (mask & (1 << bit))
		{
			if (connect[p][bit])
				++cnt;
		}
	}

	if ((cnt & 1) == vp[p])
		return true;
	else
		return false;

}

int main()
{
	init();

	int ans = 0;

	for (int mask = 0; mask < (1 << n); mask++)
	{
		bool flag = true;

		REP(i, m)
		{
			if (!check(mask, i))
			{
				flag = false;
				break;
			}
		}

		if (flag)
			++ans;
	}

	cout << ans << endl;
}
