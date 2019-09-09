#include <iostream>

using namespace std;

class A {
	int a, b, c, d;
public:
	void solve()
	{
		int ans{ a };
		if (b < a) ans = b;
		if (c < d) ans += c;
		else ans += d;

		cout << ans << endl;
	}
	A() { cin >> a >> b >> c >> d; }
};

//
//int main()
//{
//	A solution;
//	solution.solve();
//
//	return 0;
//}