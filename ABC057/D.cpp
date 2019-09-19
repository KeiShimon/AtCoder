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

#include <unordered_map>
#include <iomanip>

int n, lo, hi;
vll v;
unordered_map<ll, int> cnt;
ll C[51][51]; // C[n][k] -> nCk

void comb_table(int N)
{
	REPC(i, N)
		REPC(j, i)
		{
			if (j == 0 or j == i)
				C[i][j] = 1LL;
			else
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
}

void init()
{
	comb_table(50);
	cin >> n >> lo >> hi;
	v.resize(n);
	REP(i, n)
	{
		ll tmp; cin >> tmp;
		v[i] = tmp;

		auto p = cnt.insert(MP(tmp, 1));
		if (!p.second)
			++p.first->second;
	}

	sort(ALL(v), greater<ll>());

	//for (auto i = cnt.begin(); i != cnt.end(); i++)
	//	cout << i->first << " : " << i->second << endl;
}

int main()
{
	init();

	double bestAv = (double)accumulate(v.begin(), v.begin() + lo, 0LL) / lo;
	cout << setprecision(24) << bestAv << endl;
	ll ans = 0;

	for (int items = lo; items <= hi; items++)
	{
		if (items != lo)
		{
			bool flag = true;
			REP(i, items)
				if (v[i] != v[0]) flag = false;
			if (!flag) break;
		}
			
		unordered_map<ll, int> um;
		REP(i, items)
		{
			auto p = um.insert(MP(v[i], 1));
			if (!p.second)
				++p.first->second;
		}

		ll tmp = 1;
		for (auto it = um.begin(); it != um.end(); it++)
		{
			tmp *= C[cnt.find(it->first)->second][it->second];
		}
		ans += tmp;
	}

	cout << ans << endl;

}
