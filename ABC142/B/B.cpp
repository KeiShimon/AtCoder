#include <iostream>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
using namespace std;


int main()
{
	int n, k; cin >> n >> k;

	int ans = 0;
	REP(_i, n)
	{
		int a; cin >> a;
		if (a >= k) ++ans;
	}

	cout << ans << endl;
}
