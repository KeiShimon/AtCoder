#include "template.h"


//// MUST INCLUDE ////
#include <unordered_map>


//// MUST HAVE EXTERNAL VARIABLES ////

void generatePrimes(int n);
void factorize(int n);

unordered_map<int, int> res;
vector<int> primes;
int donePrime = 1;


void factorize(int n)
{
	if (donePrime < n)
		generatePrimes(n);

	if (n < 2)
		return;

	if (!(n & 1))
	{
		int cnt = 1;
		n >>= 1;

		while (!(n & 1))
		{
			cnt++;
			n >>= 1;
		}
		auto p = res.insert(make_pair(2, cnt));
		if (!p.second)
			p.first->second += cnt;
	}
	
	for (size_t i = 1; i < primes.size() && primes[i] <= n; i++)
	{
		int cnt = 0;
		int d = primes[i];
		while (!(n % d))
		{
			cnt++;
			n /= d;
		}
		if (cnt)
		{
			auto p = res.insert(make_pair(d, cnt));
			if (!p.second)
				p.first->second += cnt;
		}
	}
}


void generatePrimes(int n)
{
	if (n <= donePrime)
		return;

	if (primes.empty())
		primes.push_back(2);

	if (primes.back() == 2 && n > 2)
		primes.push_back(3);

	bool flag;

	for (int k = primes.back() + 2; k <= n; k += 2)
	{
		if (!(k % 3))
			continue;

		flag = true;
		int limit = (int)ceil(sqrt(k)) + 1;
		int sz{ (int)primes.size() };
		for (int i{ 2 }; i < sz && primes[i] <= limit; i++)
		{
			if (!(k % primes[i]))
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			primes.push_back(k);
			++sz;
		}
	}

	donePrime = n;
}