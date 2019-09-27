#include "template.h"

/*
		Get all divisors and store in a vector.

		O ( log N )

*/



//// MUST HAVE EXTERNAL VARIABLES ////
Vi divisors;


//// BODY ////

template <class T>
void getDivisors(T n, vector<T> v)
{
	T lim = (T)ceil(sqrt(n));

	for (int i = 1; i <=lim; ++i)
		if (!n % d)
		{
			v.push_back(d);
			v.push_back(n / d);
		}

	sort(v.begin(), v.end());
}
