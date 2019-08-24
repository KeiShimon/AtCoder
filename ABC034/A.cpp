#include <iostream>

using namespace std;

class A {
	int x, y;
public:
	void solve()
	{
		cin >> x >> y;

		if (y > x) cout << "Better" << endl;
		else cout << "Worse" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}