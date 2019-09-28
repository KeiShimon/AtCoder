#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

template <class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> void generatePrimes(T n);
template <class T> void factorize(T n);

vector<ll> primes;
int listedPrimesUpto = 1;
ll ans = 1;


int main()
{
	ll a, b; cin >> a >> b;
	ll g = gcd(a, b);

	if (g == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	factorize(g);

	cout << ans << endl;
}

template <class T> void factorize(T n)
{
	if (n < 2)
		return;

	T rt = (T)ceil(sqrt(n));

	if (listedPrimesUpto < rt)
		generatePrimes(rt);

	for (T d : primes)
	{
		if (rt < d) break;

		if (!(n % d))
		{
			++ans;
			while (!(n % d))
				n /= d;
		}
	}

	if (n != 1)
		++ans;
}

template <class T> void generatePrimes(T n)
{
	if (n <= listedPrimesUpto) return;
	if (primes.empty()) primes.push_back(2);
	if (primes.back() == 2 && n > 2) primes.push_back(3);

	bool isPrime;

	for (T k = primes.back() + 2; k <= n; k += 2)
	{
		if (!(k % 3)) continue;

		isPrime = true;
		T lim = (T)ceil(sqrt(k));

		for (T p : primes)
		{
			if (p > lim) break;
			if (!(k % p)) { isPrime = false; break; }
		}

		if (isPrime) primes.push_back(k);
	}
	listedPrimesUpto = n;
}