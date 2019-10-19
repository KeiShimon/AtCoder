#include <iostream>

using namespace std;

class A {
	int N;
public:
	void solve()
	{
		cin >> N;

		if (N == 12) cout << 1 << endl;
		else cout << (N + 1) << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}