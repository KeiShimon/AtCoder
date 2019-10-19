#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

const int MOD = 1000000007;

////// Mod int //////
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

int N, K;

// sum for all x : gcd(x, k) = g 
mint solve(int g);

// determine sign for inclusion-exclusion principle (•ïœŒ´—)
int sign(int x);

// arithmetic sum for 1 + 2 + ... + n
inline ll arithmeticSum(int n) { return (ll)n * ((ll)n + 1) / 2 % MOD; }

int main()
{
	cin >> N >> K;

	mint ans;

	// get all divisors of K
	for (int i = 1; i * i <= K; ++i)
		if (!(K % i))
		{
			int d; // d for "d"ivisor

			d = i;
			ans += solve(d) * (K / d);
			
			if (i * i != K)
			{
				d = K / i;
				ans += solve(d) * (K / d);
			}
		}

	cout << ans.x << endl;
}

mint solve(int g)
{
	// Problem
	// determine sum for all x : gcd(x, K) = g, for all x in [1, N]

	mint ret;

	int n = N / g;
	int k = K / g;

	// Converted Problem
	// determine sum for all x : gcd(x, k) = 1, for all x in [1, n]

	// such x are coprime to k, so
	// lets get sum of all x that is coprime to k !!

	for (int i = 1; i * i <= k; ++i)
		if (!(k % i)) 	// get all divisor of k
		{
			int d = i;
			
			mint s = arithmeticSum(n / d) * d; // sum for all x : x = a * d
			ret += s * sign(d); // inclusion-exclusion principle

			if (i * i != k)
			{
				d = k / i;
				mint s = arithmeticSum(n / d) * d;
				ret += s * sign(d);
			}
		}

	// revert converted problem
	ret *= g;
	return ret;
}

int sign(int x)
{
	// determine sign for inclusion-exclusion principle

	int cnt = 0; // number of factors

	for (int i = 2; i * i <= x; ++i)
	{
		if (!(x % (i * i)))
		{	// you are thinking of 4, 8, 12, ... ?? you have already done operation when it was 2, 4, 6, 8, ... !!
			return 0;
		}

		if (!(x % i))
		{
			++cnt;
			x /= i;
		}
	}

	if (x != 1) ++cnt;

	return (cnt & 1) ? -1 : 1;
}
