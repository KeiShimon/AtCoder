#include "template.h"


//// MUST HAVE EXTERNAL VARIABLES ////

template <class T> void generatePrimes(T n);
template <class T> void factorize(T n);

map<ll, int> res;
vector<ll> primes;
int listedPrimesUpto = 1;


//// BODY ////

template <class T> void factorize(T n)
{
	if (n < 2)
		return;

	T rt = (T)ceil(sqrt(n));
	if (listedPrimesUpto < rt) generatePrimes(rt);

	for (T p : primes)
	{
		if (rt < p) break;

		int cnt = 0;

		while (!(n % p))
		{
			n /= p;
			cnt++;
		}

		if (cnt)
			res[p] += cnt;
	}

	if (n != 1) res[n]++;
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