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

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

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

////////////////

int N, K;

// sum for all i : gcd(i, k) = g 
mint solve(int g);

// sum for all i : gcd(i, k) = 1 && i in [1, n]
mint calc(int k, int n);

// determine sign for inclusion-exclusion principle (•ïœŒ´—)
int sign(int x);

// arithmetic sum
inline mint arithsum(int n) { return (ll)n * ((ll)n + 1) / 2; }

int main()
{
	cin >> N >> K;
	mint ans;

	for (int i = 1; i * i <= K; ++i)
		if (!(K % i))
		{
			int d;

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

// sum for all i : gcd(i, K) = g, for all i in [1, N]
mint solve(int g)
{
	mint ret;

	int n = N / g;
	int k = K / g;

	// problem is converted : 
	// sum for all i : gcd(i, k) = 1, for all i in [1, n]

	for (int i = 1; i * i <= k; ++i)
		if (!(k % i))
		{
			int d = i;
			ret += arithsum(n / d) * d * sign(d);

			if (i * i != k)
			{
				d = k / i;
				ret += arithsum(n / d) * d * sign(d);
			}
		}

	return ret;
}

// determine sign for inclusion-exclusion principle
int sign(int x)
{
	if (x == 1)
		return 1;

	// number of factors in x
	int cnt = 0;
	int lim = ceil(sqrt(x));

	for (int d = 2; d <= lim; ++d)
	{
		while (!(x % d))
		{
			x /= d;
			++cnt;
		}
	}

	if (x != 1)
		++cnt;

	if (cnt & 1)
		return 1;
	else
		return -1;
}