#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;
typedef vector<int> Vi;
typedef vector<vector<int> > VVi;

VVi row;
Vi col, col_sorted;
int h, w, k, n;

int main()
{
	cin >> h >> w >> k >> n;
	col.resize(w);
	row.resize(h);

	REP(_i, n)
	{
		int y, x;
		cin >> y >> x;
		--y; --x;

		row[y].push_back(x);
		col[x]++;
	}

	col_sorted = col;
	sort(ALL(col_sorted));
	
	ll ans = 0;
	REP(i, h)
	{
		int r = row[i].size();
		if (r > k)
			continue;

		int c = k - r;

		auto ub = upper_bound(ALL(col_sorted), c);
		auto lb = lower_bound(ALL(col_sorted), c);

		ll n = (ub - lb);
		ans += n;

		for (auto j : row[i])
		{
			if (r + col[j] == k)
				--ans;
			else if (r + col[j] == k + 1)
				++ans;
		}
	}

	cout << ans << endl;
}
