#include <iostream>

using namespace std;

class A {
	int a, b, tmp, ans{ -10000000 };
public:
	void solve()
	{
		cin >> a >> b;

		tmp = a + b;
		if (ans < tmp) ans = tmp;
		tmp = a - b;
		if (ans < tmp) ans = tmp;
		tmp = a * b;
		if (ans < tmp) ans = tmp;

		cout << ans << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}