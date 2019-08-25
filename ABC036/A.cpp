#include <iostream>

using namespace std;

class A {
	int a, b;
public:
	void solve()
	{
		if (!(b % a)) cout << b / a << endl;
		else cout << (b / a + 1) << endl;
	}

	A() { cin >> a >> b; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}