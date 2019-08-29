#include <iostream>
#include <unordered_set>

using namespace std;

class B {
	unordered_set<string> us;
	string s;
	int n;
public:
	void solve()
	{

		char last;
		cin >> s;
		us.insert(s);
		last = s.back();

		bool flag{ true };
		for (int i{ 1 }; i < n; i++)
		{
			cin >> s;
			if (s.front() != last || !(us.insert(s).second))
			{
				flag = false;
				break;
			}
			last = s.back();
		}

		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	B()
	{
		cin >> n;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}