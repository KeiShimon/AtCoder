#include <iostream>


template <class T> bool is_prime(T n)
{
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	if (!(n & 1) || !(n % 3)) return false;

	for (T i{ 5 }; i * i <= n; i += 6)
		if (!(n % i) || !(n % (i + 2))) // 6n-1 or 6n+1
			return false;

	return true;
}