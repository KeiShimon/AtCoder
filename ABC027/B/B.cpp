#include <iostream>
#include <numeric>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;
typedef vector<int> Vi;

int main()
{
	int n; cin >> n;
	Vi va(n);
	REP(i, n) cin >> va[i];

	int s = accumulate(ALL(va), 0);
	int ave = s / n;

	if (ave * n != s)
	{
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;
	int tmp = 0;
	REP(i, n)
	{
		if (tmp != 0)
			++ans;
		tmp += va[i] - ave;
	}

	cout << ans << endl;
}
