#include <iostream>
#include <cmath>

using namespace std;

class A {
	int x, a, b;
public:
	void solve()
	{
		cin >> x >> a >> b;

		if (abs(x - a) < abs(x - b)) cout << "A" << endl;
		else cout << "B" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}