#include <iostream>
#include <string>

using namespace std;


class A {
	int n, m;

public:
	void solve()
	{
		cin >> n >> m;

		cout << (n - 1) * (m - 1) << endl;
	}
};

class B {
	string s;

public:
	void solve()
	{
		cin >> s;

		cout << s.front() << s.length() - 2 << s.back() << endl;
	}

};

int main()
{
	A solution;
	solution.solve();
	return 0;
}