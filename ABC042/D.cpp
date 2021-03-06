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

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


vector<int64_t> factMemo{ 1,1 }, factInvMemo{ 1, 1 }, invMemo{ 0, 1 };
int curMax{ 1 };


void initTable(int n) {

	factMemo.resize(n + 1);
	factInvMemo.resize(n + 1);
	invMemo.resize(n + 1);

	for (; curMax < n;)
	{
		curMax++;
		factMemo[curMax] = factMemo[curMax - 1] * curMax % MOD;
		invMemo[curMax] = MOD - invMemo[MOD % curMax] * (MOD / curMax) % MOD;
		factInvMemo[curMax] = factInvMemo[curMax - 1] * invMemo[curMax] % MOD;
	}
}


// calculate mod of combination
int64_t comb(int n, int k) {
	if (n < k)
		return 0;
	if (n < 0 || k < 0)
		return 0;

	if (curMax < n)
		initTable(n);

	return factMemo[n] * (factInvMemo[k] * factInvMemo[n - k] % MOD) % MOD;
}


int64_t comb(int64_t n, int64_t k)
{
	return comb((int)n, (int)k);
}


int main()
{
	ll h, w, a, b; cin >> h >> w >> a >> b;

	if (w - b == 1)
	{
		if (h - a == 1)
			{ cout << 1 << endl; return 0; }

		ll ans = comb((h - a - 1) + (w - 1), w - 1);
		cout << ans << endl;
		return 0;
	}
	else if (h - a == 1)
	{
		ll ans = comb((w - b - 1) + a, a) % MOD;
		cout << ans << endl;
		return 0;
	}

	ll ans = comb(b + (h - a - 1), b);
	ans = ans * comb((w - b - 1) + a, a) % MOD;

	REP1O(i, h - a)
	{
		ll tmp = comb(b + (i - 1), b);
		tmp = tmp * comb((w - b - 2) + (h - i), h - i) % MOD;
		ans = (tmp + ans) % MOD;
	}

	cout << ans << endl;
}