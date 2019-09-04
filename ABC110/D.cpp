#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i > 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class D {
	int n, m;
	const int MOD{ 1000000007 };

public:
	D()
	{
		cin >> n >> m;
	}

	ll modinv(ll a, ll b) {
		if (!b)
			return 1;

		if (b & 1)
			return a * modinv(a, b - 1) % MOD;
		else
		{
			ll half = modinv(a, b / 2);
			return half * half % MOD;
		}
		
	}

	ll comb(int a, int b)
	{
		if (b > a - b)
			return comb(a, a - b);

		ll denominator{ 1 };
		ll numerator{ 1 };

		REP(i, b)
		{
			denominator *= (b - i);
			denominator %= MOD;
			numerator *= (a - i);
			numerator %= MOD;
		}

		return numerator * modinv(denominator, MOD - 2) % MOD;
	}

	void solve()
	{

		int tmp{ m };
		ll ans{ 1 };

		int div{ 2 };
		int cnt{ 0 };

		while (!(tmp & 1))
		{
			cnt++;
			tmp >>= 1;
		}
		if (cnt)
			ans = comb(n + cnt - 1, cnt) % MOD;

		for (div = 3; div <= tmp; div += 2)
		{
			cnt = 0;

			while (!(tmp % div))
			{
				cnt++;
				tmp /= div;
			}

			if (cnt)
			{
				ans *= comb(n + cnt - 1, cnt);
				ans %= MOD;
			}
		}

		cout << ans << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}