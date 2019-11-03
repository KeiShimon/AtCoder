#include "template.h"

/*

powmod version for calculating the mod of combination

Useful when:
	only few queries that includes combination are expected

Time complexity:
	O (log(MOD)) for each query

Space complexity:
	zero
*/

ll powmod(ll, ll);
ll powmod(int b, int a) { return powmod((ll)b, (ll)a); }
ll comb(ll, ll);
ll comb(int a, int b) { return comb((ll)a, (ll)b); }


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
	if (a < b || b < 0)
		return 0;

	if (!b || a == b)
		return 1;

	ll numerator = a % MOD;
	ll denominator = b % MOD;

	for (int i = 1; i < b; ++i)
	{
		numerator = numerator * (a - i) % MOD;
		denominator = denominator * (b - i) % MOD;
	}

	return numerator * powmod(denominator, (ll)MOD - 2) % MOD;
}
