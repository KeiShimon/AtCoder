#include <iostream>
#include <string>

using namespace std;

class B {
	bool appeared[26]{ false };
	string s;
public:
	void solve()
	{
		cin >> s;

		for (char c : s)
			appeared[c - 'a'] = true;

		for (int i{ 0 }; i < 26; i++)
		{
			if (!appeared[i])
			{
				cout << (char)(i + (int)'a') << endl;
				return;
			}
		}

		cout << "None" << endl;
	}

};


int main()
{
	B solution;
	solution.solve();

	return 0;
}