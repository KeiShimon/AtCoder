#include <iostream>
#include <string>

using namespace std;

class A {
	string a, b, c;
public:
	void solve()
	{
		cin >> a >> b >> c;

		if ((a.back() == b.front()) && (b.back() == c.front())) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}