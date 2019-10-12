#include "template.h"

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