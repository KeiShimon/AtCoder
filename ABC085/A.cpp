#include <unordered_set>
#include <iostream>
#include <string>


using namespace std;

class A {
	string S;

public:
	void solve()
	{
		cin >> S;

		cout << "2018" << S.substr(4) << endl;
	}
};

int main()
{
	A solution;
	solution.solve();
	return 0;
}