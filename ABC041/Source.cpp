#include <iostream>
#include <string>

using namespace std;

class A {
	string s;
	int i;

public:
	void solve()
	{
		cin >> s >> i;
		cout << s[i - 1] << endl;
	}
};


int main()
{
	A solve;
	solve.solve();
}