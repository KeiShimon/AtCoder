#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class C {
	int n;
public:
	void solve()
	{
		vector<int> a(n);
		vector<int> ans;

		for (int i{ 0 }; i < n; i++)
			cin >> a[i];

		if (n & 1)
		{
			// odd items
			// id even -> 0 1 -> odd

			for (int i{ n - 1 }; i >= 0; i -= 2)
				ans.push_back(a[i]);
			for (int i{ 1 }; i < n; i += 2)
				ans.push_back(a[i]);
		}

		else
		{
			// even items
			// id odd -> 1 0 ->even

			for (int i{ n - 1 }; i >= 1; i -= 2)
				ans.push_back(a[i]);
			for (int i{ 0 }; i < n; i += 2)
				ans.push_back(a[i]);
		}

		for (int i{ 0 }; i < n; i++)
		{
			cout << ans[i];
			if (i != n - 1) cout << " ";
			else cout << endl;
		}

	}

	C() { cin >> n; }
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}