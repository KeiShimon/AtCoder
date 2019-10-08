#include <iostream>

using namespace std;

typedef int64_t ll;
ll op1(ll x) { x <<= 1; return x; }
ll op2(ll x) { x <<= 1; return ++x; }

int main()
{
	ll n; cin >> n;

	if (n == 1)
	{
		cout << "Aoki" << endl;
		return 0;
	}

	int depth = 0;
	for (ll tmp = n; tmp; tmp >>= 1)
		++depth;
	
	ll (*func[])(ll) = { op1, op1 };

	if (depth & 1)
		func[0] = op2;
	else
		func[1] = op2;

	ll x = 1;
	int p = 0;

	while (x <= n)
	{
		x = (*func[p])(x);
		p ^= 1;
	}

	if (!p)
		cout << "Takahashi" << endl;
	else
		cout << "Aoki" << endl;
}
