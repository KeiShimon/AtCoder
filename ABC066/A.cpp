#include <iostream>

using namespace std;

class A {
	int a, b, c, ans;
public:
	void solve()
	{
		cin >> a >> b >> c;

		ans = a + b;
		
		if (a + c < ans) ans = a + c;
		if (b + c < ans) ans = b + c;

		cout << ans << endl;

	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}