#include <iostream>
#include <cmath>

using namespace std;


class B {
	int X;

public:
	void solve()
	{
		cin >> X;

		int ans{ (int)sqrt(X) };
		ans = sqrt(ans);

		cout << ans << endl;
	}
};


int main()
{
	B solution;
	solution.solve();
	return 0;
}