#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

typedef int64_t ll;
const int MOD = 1000000007;

ll powmod(ll b, ll e) {
	ll ret = 1;
	while (e)
	{
		if (e & 1) ret = ret * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return ret;
}

ll comb(ll a, ll b)
{
	ll numerator = a % MOD;
	ll denominator = b % MOD;

	for (int i = 1; i < b; ++i)
	{
		numerator = numerator * (a - i) % MOD;
		denominator = denominator * (b - i) % MOD;
	}

	return numerator * powmod(denominator, MOD - 2) % MOD;
}

int main()
{
	ll n, k;
	cin >> n >> k;

	cout << comb(n + k - 1, k) << endl;
}
