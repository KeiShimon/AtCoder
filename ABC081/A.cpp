#include <iostream>

using namespace std;

class A {
	string S;
public:
	void solve()
	{
		cin >> S;

		int ans{ 0 };

		if (S[0] == '1') ++ans;
		if (S[1] == '1') ++ans;
		if (S[2] == '1') ++ans;

		cout << ans << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}