#include <iostream>

using namespace std;

class A {
	int x, y;
public:
	void solve()
	{
		cin >> x >> y;
		cout << (x + y / 2) << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}