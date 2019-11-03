#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;
typedef vector<int> Vi;

int n;
Vi desc, asc;

int main()
{
	cin >> n;
	desc.resize(n);
	REP(i, n) cin >> desc[i];
	sort(ALL(desc), greater<>());
	asc = desc;
	reverse(ALL(asc));

	ll ans = 0;
	REP(i_c, n - 2)
	{
		int c = desc[i_c];
		for (int i_b = i_c + 1; i_b < n - 1; ++i_b)
		{
			int b = desc[i_b];
			int hi = b;
			int lo = c + 1 - b;

			if (lo > hi)
				break;

			ll cnt = upper_bound(asc.begin(), asc.end() - 1- i_b, hi)\
				- lower_bound(asc.begin(), asc.end() - 1- i_b, lo);
			
			ans += cnt;
		}
	}

	cout << ans << endl;
}
