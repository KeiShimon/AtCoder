#include <iostream>

using namespace std;


// calculate inverse mod of a for m
// WARNING inverse mod does not exist if a == mb
int64_t modInv(int64_t a, int64_t m)
{
	int64_t b{ m };
	int64_t u{ 1 }, v{ 0 };
	
	while (b)
	{
		int64_t t{ a / b };
		a -= t * b;
		a ^= b; b ^= a; a ^= b;
		u -= t * v;
		u ^= v; v ^= u; u ^= v;
	}

	u %= m;

	return (u < 0) ? u + m : u;
}

