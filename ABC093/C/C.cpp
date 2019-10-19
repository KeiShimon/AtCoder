#include <iostream>
#include <algorithm>

using namespace std;

class C {
	int a, b, c;
public:
	void solve()
	{
		int target{ max(a, max(b, c)) * 3 };
		int current{ a + b + c };
		target -= current;

		if (1 & target) target += 3;

		cout << target / 2 << endl;

	}
	C()
	{
		cin >> a >> b >> c;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}