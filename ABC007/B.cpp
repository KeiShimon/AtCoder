#include <iostream>

using namespace std;

class B {
	string A;
public:
	void solve()
	{
		if (A.size() > 1)
		{
			cout << A.substr(0, 1) << endl;
		}
		else if (A[0] != 'a')
		{
			cout << (char)(A[0] - 1) << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}

	B() { cin >> A; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}