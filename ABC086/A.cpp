#include <iostream>

using namespace std;

class A {
	int a, b;
public:
	void solve()
	{
		cin >> a >> b;

		if ((~a | ~b) & 1) cout << "Even" << endl;
		else cout << "Odd" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}