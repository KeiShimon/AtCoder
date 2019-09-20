#include "template.h"


vector<int> primes;
void generatePrimes(int n);
int donePrime = 1;


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

//int main()
//{
//	generatePrimes(100);
//	generatePrimes(50);
//	generatePrimes(200);
//
//	REP(i, SZ(primes))
//		cout << primes[i] << " ";
//	cout << endl;
//}