#include <iostream>
#include <set>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef int64_t ll;
typedef vector<int> Vi;

int n;
Vi vi;

void init()
{
	cin >> n;
	vi.resize(n + 1);

	REP(i, n)
	{
		int x;
		cin >> x;
		vi[x] = i + 1;
	}
}


int main()
{
	init();

	ll ans = 0;
	multiset<int> s;

	s.insert(0); s.insert(0);
	s.insert(n + 1); s.insert(n + 1);

	for (ll x = n; x >= 1; --x)
	{
		auto it = s.lower_bound(vi[x]);
		int i_r = *it++;
		int i_rr = *it--;
		int i_l = *(--it);
		int i_ll = *(--it);

		ans += x * (vi[x] - i_l) * (i_rr - i_r);
		ans += x * (i_r - vi[x]) * (i_l - i_ll);

		s.insert(vi[x]);
	}

	cout << ans << endl;
}
