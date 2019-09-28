#include "template.h"


vector<ll> primes;
template <class T> void generatePrimes(T n);
ll listedPrimesUpto = 1;


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
