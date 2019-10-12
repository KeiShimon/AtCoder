#include "template.h"


//// MUST HAVE EXTERNAL VARIABLES ////

template <class T> void factorize(T n, map<int, int>& res);
map<int, int> res_fact;


template <class T> void factorize(T n, map<int, int>& res)
{
	if (n < 2)
		return;

	T lim = (T)ceil(sqrt(n));
	int cnt, d;

	cnt = 0; d = 2;
	while (!(n % d))
		n /= d, ++cnt;
	if (cnt)
		res.insert(make_pair(d, cnt));

	cnt = 0; d = 3;
	while (!(n % d))
		n /= d, ++cnt;
	if (cnt)
		res.insert(make_pair(d, cnt));

	for (d = 5; d <= lim; d += 2)
	{
		if (!(d % 3))
			continue;

		cnt = 0;
		while (!(n % d))
			n /= d, ++cnt;
		if (cnt)
			res.insert(make_pair(d, cnt));
	}

	if (n != 1)
		res.insert(make_pair(n, 1));
}
