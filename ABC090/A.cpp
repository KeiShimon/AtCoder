#include <iostream>
#include <string>

using namespace std;

class A {
	string s;
public:
	void solve()
	{
		for (int i{ 0 }; i < 3; i++)
		{
			cin >> s;
			cout << s[i];
		}

		cout << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}