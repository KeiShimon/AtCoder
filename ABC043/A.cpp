#include <iostream>

using namespace std;

class A {
	int n;
public:
	void solve()
	{
		cin >> n;

		cout << ((1 + n) * n / 2) << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}