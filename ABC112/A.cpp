#include <iostream>

using namespace std;

class A {
	int N, a, b;
public:
	void solve()
	{
		if (N == 1)
			cout << "Hello World" << endl;
		else
			cout << (a + b) << endl;
	}

	A()
	{
		cin >> N >> a >> b;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}