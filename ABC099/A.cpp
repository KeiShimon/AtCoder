#include <iostream>

using namespace std;

class A {
	int N;
public:
	void solve()
	{
		cin >> N;

		if (N < 1000) cout << "ABC" << endl;
		else cout << "ABD" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}