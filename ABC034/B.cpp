#include <iostream>

using namespace std;

class B {
	int n;
public:
	void solve()
	{
		cin >> n;

		if (n & 1) cout << n + 1 << endl;
		else cout << n - 1 << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}