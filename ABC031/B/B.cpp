#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef vector<int> Vi;

int main()
{
	int lo, hi; cin >> lo >> hi;
	int n; cin >> n;

	Vi v(n);
	REP(i, n) cin >> v[i];

	for (int x : v)
	{
		if (x < lo)
			cout << lo - x << endl;
		else if (x > hi)
			cout << -1 << endl;
		else
			cout << 0 << endl;
	}
}
