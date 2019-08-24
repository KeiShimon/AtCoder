#include <iostream>
#include <string>

using namespace std;


class C {
	string s;
	int ans{ 0 };
public:
	void solve()
	{
		cin >> s;
		bool is_zero{ false };

		for (char c: s)
		{
			if (c == '+')
			{
				if (!is_zero) ans++;
				is_zero = false;
			}
			else if (c == '*')
			{
				continue;
			}
			else
			{
				if (!is_zero)
				{
					if (c == '0') is_zero = true;
				}
			}
		}

		if (!is_zero) ans++;

		cout << ans << endl;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}