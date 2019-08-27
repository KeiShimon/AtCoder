#include <iostream>

using namespace std;

class A {
	int T, X;
public:
	void solve()
	{
		double ans{ (double)T / X };
		cout << ans << endl;
	}

	A() { cin >> T >> X; }
};

int main()
{
	A solution;
	solution.solve();

	return 0;
}