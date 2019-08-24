#include <iostream>

using namespace std;

class A {
	int a, b, c;
public:
	void solve()
	{
		cin >> a >> b >> c;

		int ans[3]{1, 1, 1};

		if (a < b) ans[0]++;
		else ans[1]++;

		if (a < c) ans[0]++;
		else ans[2]++;

		if (b < c) ans[1]++;
		else ans[2]++;

		for (int i{ 0 }; i < 3; i++)
			cout << ans[i] << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}