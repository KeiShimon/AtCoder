#include <iostream>

using namespace std;

class A {
	int a, b, h;
public:
	void solve()
	{
		cin >> a >> b >> h;
		cout << ((a + b) * h / 2) << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}