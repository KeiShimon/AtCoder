#include <cmath>
#include <vector>

using namespace std;

vector<int> primes;
void generatePrimes(int n);


void generatePrimes(int n)
{

	const int originPrimes[10]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

	for (int i{ 0 }; i < 10; i++)
	{
		if (originPrimes[i] > n)
			return;

		primes.push_back(originPrimes[i]);
	}

	bool flag{ true };

	for (int k{ 31 }; k <= n; k += 2)
	{
		flag = true;
		int limit = (int)ceil(sqrt(k)) + 1;
		int sz{ (int)primes.size() };
		for (int i{ 0 }; i < sz && primes[i] < limit; i++)
		{
			if (!(k % primes[i]))
			{
				flag = false;
				break;
			}
		}

		if (flag)
			primes.push_back(k);
	}

	flag = true;
	k = n;
	for (int d : primes)
	{
		if (!(k % d))
		{
			flag = false;
			break;
		}
	}

	if (flag)
		primes.push_back(k);

}

