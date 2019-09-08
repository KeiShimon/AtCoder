#include <iostream>

bool is_prime(const int64_t n)
{
	if (n == 1)
		return false;

	if (n == 2 || n == 3)
		return true;

	if (!(n & 2) || !(n % 3))
		return false;

	for (int64_t i{ 5 }; i * i <= n; i += 6)
		if (!(n % i) || !(n % (i + 2))) // 6n-1 or 6n+1
			return false;

	return true;
}