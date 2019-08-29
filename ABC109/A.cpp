#include <iostream>

using namespace std;

class A {
	int a, b;
public:
	void solve()
	{
		if ((a & 1) && (b & 1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	A()
	{
		cin >> a >> b;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}