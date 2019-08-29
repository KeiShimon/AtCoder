#include <iostream>

using namespace std;

class A {
	int a, b;
public:
	void solve()
	{

		if ((a <= 8) && (b <= 8)) cout << "Yay!" << endl;
		else cout << ":(" << endl;

	}

	A() { cin >> a >> b; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}