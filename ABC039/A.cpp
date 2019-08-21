#include <iostream>
#include <cmath>

using namespace std;


class A {
	int A, B, C;

public:
	void solve()
	{
		cin >> A >> B >> C;

		cout << ((2 * A * B) + (2 * B * C) + (2 * A * C)) << endl;
	}
};



int main()
{
	A solution;
	solution.solve();
	return 0;
}