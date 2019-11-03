#include <algorithm>
#include <cmath>
#include <iostream>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef int64_t ll;

const int MOD = 1000000007;

// Mod int //////
struct mint {
	ll x;
	mint() :x(0) {}
	mint(ll x) :x((x% MOD + MOD) % MOD) {}
	// mint(ll x):x(x){}
	mint& fix() { x = (x % MOD + MOD) % MOD; return *this; }
	mint operator-() const { return mint(0) - *this; }
	mint& operator+=(const mint& a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
	mint& operator-=(const mint& a) { if ((x += MOD - a.x) >= MOD) x -= MOD; return *this; }
	mint& operator*=(const mint& a) { (x *= a.x) %= MOD; return *this; }
	mint operator+(const mint& a)const { return mint(*this) += a; }
	mint operator-(const mint& a)const { return mint(*this) -= a; }
	mint operator*(const mint& a)const { return mint(*this) *= a; }
	bool operator<(const mint& a)const { return x < a.x; }
	bool operator==(const mint& a)const { return x == a.x; }
};
istream& operator>>(istream& i, mint& a) { i >> a.x; return i; }
ostream& operator<<(ostream& o, const mint& a) { o << a.x; return o; }

////////////////////////////////////////////////////////////////////////////////////

ll H, W, X, Y, D, L;

ll powmod(ll, ll);
ll powmod(int b, int a) { return powmod((ll)b, (ll)a); }
ll comb(ll, ll);
ll comb(int a, int b) { return comb((ll)a, (ll)b); }

mint countArrangements(ll x, ll y)
{

	if (!x || !y)
		return 0;

	ll a = x * y;
	if (a < D + L)
		return 0;

	mint ret = comb(a, D);
	ret *= comb(a - D, L);

	return ret;
}

int main()
{
	cin >> H >> W >> Y >> X >> D >> L;

	mint pat = (H - Y + 1) * (W - X + 1);
	mint ans = countArrangements(X, Y);

	REP(dx, X)
		REP(dy, Y)
	{
		if (!dx && !dy)
			continue;

		int sign = ((dx + dy) & 1) ? -1 : 1;
		ans += countArrangements(X - dy, Y - dy) * 2 * sign;
	}

	ans *= pat;

	cout << ans << endl;
}

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
