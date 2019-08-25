#include <iostream>

using namespace std;

class A {
	string S;
public:
	void solve()
	{
		cin >> S;
		S[5] = S[13] = ' ';
		cout << S << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}