#include <iostream>
#include <cctype>

using namespace std;

class B {
	string S;
public:
	void solve()
	{
		cin >> S;

		cout << (char)toupper(S[0]);

		if (S.size() > 1)
		{
			for (int i{ 1 }; i < S.size(); i++)
				cout << (char)tolower(S[i]);
		}

		cout << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}