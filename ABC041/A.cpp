#include <iostream>
#include <string>

using namespace std;

class A {
	string s;
	int i;

public:
	A() {
		cin >> s >> i;
	}
	void solve()
	{
		cout << s[i - 1] << endl;
	}
};


int main()
{
	A solve;
	solve.solve();
}