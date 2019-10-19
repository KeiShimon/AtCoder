#include <iostream>
#include <algorithm>

using namespace std;

class B {
	int a, b, k;
public:
	void solve()
	{
		int lower_bound{ max(a, b - k + 1) };
		int upper_bound{ min(b, a + k - 1) };

		if (upper_bound >= lower_bound)
		{
			for (int i{ a }; i <= b; i++)
				cout << i << endl;
		}
		else
		{
			for (int i{ a }; i <= upper_bound; i++)
				cout << i << endl;
			for (int i{ lower_bound }; i <= b; i++)
				cout << i << endl;
		}
	}

	B()
	{
		cin >> a >> b >> k;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}