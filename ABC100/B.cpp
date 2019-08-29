#include <iostream>
#include <sstream>
using namespace std;

class B {
	int d, n;
public:
	void solve()
	{
		ostringstream oss;
		if (n == 100)
			oss << (n + 1);
		else
			oss << n;
		for (int i{ 0 }; i < d; i++)
			oss << "00";

		cout << oss.str() << endl;
	}

	B() { cin >> d >> n; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}