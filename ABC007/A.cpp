#include <iostream>

using namespace std;

class A {
	int n;
public:
	void solve()
	{
		cout << n - 1 << endl;
	}

	A() { cin >> n; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}