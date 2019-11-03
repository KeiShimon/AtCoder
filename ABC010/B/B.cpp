#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

int main()
{
	int ans = 0;
	int n; cin >> n;

	REP(_i, n)
	{
		int a;
		cin >> a;
		while (!(a & 1) || a % 3 == 2)
			--a, ++ans;
	}

	cout << ans << endl;
}
