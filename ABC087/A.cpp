#include <iostream>

using namespace std;

class A {
	int x, a, b;
public:
	void solve()
	{
		x -= a;
		cout << (x % b) << endl;
	}
	A() { cin >> x >> a >> b; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}