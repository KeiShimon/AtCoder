#include <iostream>

using namespace std;

class B {
	int a, b, c;
public:
	void solve()
	{
		cin >> a >> b >> c;
		bool flag{ false };
		for (int n{ a }; n <= a * b; n += a)
		{
			if ((n % b) == c)
			{
				flag = true;
				break;
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}