#include <iostream>

using namespace std;


class A {
	int N;
public:
	void solve()
	{
		cin >> N;
		cout << (800 * N - 200 * (N / 15)) << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}