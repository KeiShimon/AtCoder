#include <iostream>

using namespace std;

class B {
	int a, b;
public:
	void solve()
	{
		cin >> a >> b;

		cout << ((1 + b - a) * (b - a) / 2 - b) << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}