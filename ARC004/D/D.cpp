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

#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++)

typedef int64_t ll;

const int MOD = 1000000007;

int n, m;
bool negative;

ll comb(ll, ll);
ll comb(int, int);
void initTable(int);
template <class T> void factorize(T n, map<int, int>& res);

map<int, int> res_fact;
vector<ll> factMemo{ 1,1 }, factInvMemo{ 1, 1 }, invMemo{ 0, 1 };
int curMax{ 1 };

ll powmod(ll b, ll e) 
{
	ll ret = 1;
	while (e)
	{
		if (e & 1) ret = ret * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return ret;
}

int main()
{
	cin >> n >> m;

	if (n & (1 << 31))
		negative = true, n = -n;

	factorize(n, res_fact);

	ll ans = 1;

	REPIT(it, res_fact)
	{
		int e = it->second;

		ll tmp = comb(m + e - 1, e);

		ans = ans * tmp % MOD;
	}

	ans = ans * powmod(2, m - 1) % MOD;

	cout << ans << endl;

}

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

ll comb(ll n, ll k) { return comb((int)n, (int)k); }
ll comb(int n, int k) {
	if (n < k || n < 0 || k < 0)
		return 0;

	if (curMax < n)
		initTable(n);

	return factMemo[n] * (factInvMemo[k] * factInvMemo[n - k] % MOD) % MOD;
}


template <class T> void factorize(T n, map<int, int>& res)
{
	if (n < 2)
		return;

	T lim = (T)ceil(sqrt(n));
	int cnt, d;

	cnt = 0; d = 2;
	while (!(n % d))
		n /= d, ++cnt;
	if (cnt)
		res.insert(make_pair(d, cnt));

	cnt = 0; d = 3;
	while (!(n % d))
		n /= d, ++cnt;
	if (cnt)
		res.insert(make_pair(d, cnt));

	for (d = 5; d <= lim; d += 2)
	{
		if (!(d % 3))
			continue;

		cnt = 0;
		while (!(n % d))
			n /= d, ++cnt;
		if (cnt)
			res.insert(make_pair(d, cnt));
	}

	if (n != 1)
		res.insert(make_pair(n, 1));
}
