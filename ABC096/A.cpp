#include <iostream>

using namespace std;

class A {
	int a, b;
public:
	void solve()
	{
		if (a > b)
			std::cout << a - 1 << endl;
		else
			std::cout << a << endl;
	
	}
	A() { cin >> a >> b; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}