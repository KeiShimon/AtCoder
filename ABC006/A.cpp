#include <iostream>
#include <string>

using namespace std;

class A {
	int n;
public:
	void solve()
	{
		cin >> n;

		if (!(n % 3)) cout << "YES" << endl;
		else if (to_string(n).find("3") == string::npos) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}