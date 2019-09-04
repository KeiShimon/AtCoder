#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;


unordered_map<int, int> factorize(int n)
{
	unordered_map<int, int> res;

	if (n < 2)
		return res;

	int x{ n };
	int cnt{ 0 };

	while (!(x & 1))
	{
		cnt++;
		x >>= 1;
	}
	if (cnt)
	{
		res.insert(make_pair(2, cnt));
		cnt = 0;
	}

	if (x > 2)
	{
		while (!(x % 3))
		{
			cnt++;
			x /= 3;
		}
		if (cnt)
		{
			res.insert(make_pair(3, cnt));
			cnt = 0;
		}
	}

	if (x > 4)
	{
		while (!(x % 5))
		{
			cnt++;
			x /= 5;
		}
		if (cnt)
		{
			res.insert(make_pair(5, cnt));
			cnt = 0;
		}
	}

	int limit{ sqrt(x) + 1 };
	for (int d{ 7 }; d < limit; d += 2)
	{
		if (d % 3 == 0 || d % 5 == 0)
			continue;

		while (!(x % d))
		{
			cnt++;
			x /= d;
		}
		if (cnt)
		{
			res.insert(make_pair(d, cnt));
			cnt = 0;
		}
	}

	if (x)
		res.insert(make_pair(x, 1));

	return res;
}