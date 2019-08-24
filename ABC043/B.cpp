#include <iostream>

using namespace std;

class B {
	string s, ans;
public:
	void solve()
	{
		cin >> s;

		for (char c : s)
		{
			if (c == 'B')
			{
				if (ans.size() > 0)
					ans.pop_back();
			}

			else
				ans.push_back(c);
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