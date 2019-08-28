#include <iostream>

using namespace std;

class B {
	int a, b, c;
	int k;
public:
	void solve()
	{
		int maximum{ a };
		if (maximum < b) maximum = b;
		if (maximum < c) maximum = c;

		int ans{ a + b + c - maximum };
		ans += (maximum <<= k);
		
		cout << ans << endl;
	}

	B() { cin >> a >> b >> c >> k; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}