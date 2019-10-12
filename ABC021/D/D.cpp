#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const int inf = 1 << 28;
const ll linf = 1LL << 60;
const int MOD = 1000000007;

ll comb(ll, ll);
ll comb(int, int);
void initTable(int);

vector<ll> factMemo{ 1,1 }, factInvMemo{ 1, 1 }, invMemo{ 0, 1 };
int curMax{ 1 };


int main()
{
	int n, k;
	cin >> n >> k;

	cout << comb(n + k - 1, k) << endl;
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
