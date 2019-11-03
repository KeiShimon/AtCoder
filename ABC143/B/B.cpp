#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

int n;
int vd[100];

int main()
{
	cin >> n;
	REP(i, n) cin >> vd[i];

	int ans = 0;
	REP(i, n - 1)
		for (int j = i + 1; j < n; ++j)
			ans += vd[i] * vd[j];
	cout << ans << endl;
}
