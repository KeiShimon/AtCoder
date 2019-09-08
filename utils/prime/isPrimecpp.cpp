#include <iostream>

bool is_prime(const int64_t n)
{
	switch (n) {
	case 0: return false;
	case 1: return false;
	case 2: return true;
	case 3: return true;
	} 

	if (!(n & 2))
		return false;
	if (!(n % 3))
		return false;

	if ( (n % 6 != 1) && (n % 6 != 5) )
		return false;

	for (unsigned i = 5; i * i <= n; i += 6) {
		if (n % i == 0) return false; // 6n-1
		if (n % (i + 2) == 0) return false; // 6n+1
	}

	return true;
}