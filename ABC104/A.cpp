#include <iostream>

using namespace std;

class A {
	int R;
public:
	void solve()
	{
		cin >> R;
		if (R < 1200) cout << "ABC";
		else if (R < 2800) cout << "ARC";
		else cout << "AGC";

		cout << endl;

	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}