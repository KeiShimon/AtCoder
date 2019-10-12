#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

typedef int64_t ll;

template <class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll x, y;
char _c;

int main()
{
	cin >> x >> _c >> y;

	if (x < y)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	ll g = gcd(x, y);
	x /= g; y /= g;

	ll n, m, k = 1;
	bool flag = true, found = false;

	n = k * y;
	m = n * (n + 1) / 2 - k * x;

	if (m < 0)
	{
		k = (ll)ceil((2 * x - y) / (y * y));
		n = k * y;
		m = n * (n + 1) / 2 - k * x;
	}

	while (flag)
	{
		if (m <= n)
		{
			if (m > 0)
			{
				cout << n << " " << m << endl;
				found = true;
			}
		}
		else
			flag = false;

		++k;
		n = k * y;
		m = n * (n + 1) / 2 - k * x;

	}

	if (!found)
		cout << "Impossible" << endl;
}
