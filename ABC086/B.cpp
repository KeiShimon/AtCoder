#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class B {
	string a, b;
	int x;
public:
	void solve()
	{
		cin >> a >> b;
		a += b;

		x = stoi(a);

		if (x == (pow((int)sqrt(x), 2))) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}