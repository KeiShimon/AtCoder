#include <iostream>
#include <string>

using namespace std;


class A {
	string s1, s2;
public:
	void solve()
	{
		cin >> s1 >> s2;

		if (s1[0] == s2[2] && s1[1] == s2[1] && s1[2] == s2[0]) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}