#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> Vi;

int n, m, x, y;
Vi va, vb;

int main()
{
	cin >> n >> m >> x >> y;
	va.resize(n);
	vb.resize(m);

	REP(i, n) cin >> va[i];
	REP(i, m) cin >> vb[i];

	int now = 0;
	int ans = 0;
	while (true)
	{
		auto it_a = lower_bound(ALL(va), now);

		if (it_a == va.end())
			break;
		else
		{
			now = *it_a + x;
		}

		auto it_b = lower_bound(ALL(vb), now);
		if (it_b == vb.end())
			break;
		else
		{
			now = *it_b + y;
			++ans;
		}
	}

	cout << ans << endl;
}
