#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef int64_t ll;

const ll linf = 1LL << 31;
int q;
ll query[2][100];

int main()
{
	cin >> q;
	REP(i, q)
		cin >> query[0][i] >> query[1][i];

	REP(i, q)
	{
		ll a = query[0][i], b = query[1][i];

		if (a == b)
		{
			cout << 2 * a - 2 << endl;
			continue;
		}

		ll ok = 0, ng = linf;
		while (ng - ok > 1)
		{
			ll mid = (ng + ok) / 2;
			ll x = (mid + 1) / 2;
			ll y = 1 + mid - x;
			
			if (x * y < a * b)
				ok = mid;
			else
				ng = mid;
		}

		ll ans = ok - 1;

		cout << ans << endl;
	}
}
