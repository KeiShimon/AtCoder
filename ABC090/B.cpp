#include <iostream>
#include <string>

using namespace std;

class B {
	int a, b, ans{ 0 };
public:
	void solve()
	{
		cin >> a >> b;

		string xs;
		for (int x{ a }; x <= b; x++)
		{
			xs = to_string(x);

			if (xs[0] == xs[4] && xs[1] == xs[3]) ans++;
		}

		cout << ans << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}