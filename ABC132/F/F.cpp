#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<ll> Vl;

const int MOD = 1000000007;

void init();

int k, n_keys;
ll n;
Vl keys, mul;

int main()
{
	init();

	Vl dp(n_keys, 0);
	dp[0] = 1;

	REP(_i, k)
	{
		Vl newdp(n_keys, 0);

		REP(i, n_keys)
			newdp[n_keys - 1 - i] = dp[i];

		for (int i = n_keys - 2; i >= 0; --i)
			newdp[i] = (newdp[i] + newdp[i + 1]) % MOD;

		REP(i, n_keys)
			newdp[i] = newdp[i] * mul[i] % MOD;

		swap(dp, newdp);
	}

	ll ans = accumulate(ALL(dp), 0LL) % MOD;
	cout << ans << endl;
}

void init()
{
	cin >> n >> k;

	int i = 1;
	while (i <= n / i)
	{
		keys.PB(i);
		keys.PB(n / i);
		++i;
	}
	sort(ALL(keys));
	n_keys = SZ(keys);

	mul.resize(n_keys);
	mul[0] = 1;
	REP1O(i, n_keys)
		mul[i] = keys[i] - keys[i - 1];
}