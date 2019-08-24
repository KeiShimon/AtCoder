#include <iostream>

using namespace std;


#define WA cout << "WA" << endl; return;


class B {
	string S;
public:
	void solve()
	{
		cin >> S;

		bool containsC{ false };

		if (S[0] != 'A')
		{
			WA
		}

		if (S[1] <= 'Z' || S.back() <= 'Z')
		{
			WA
		}

		for (int i{ 2 }; i < S.size() - 1; i++)
		{
			if (S[i] == 'C')
			{
				if (containsC)
				{
					WA
				}
				containsC = true;
			}

			else
			{
				if (S[i] <= 'Z')
				{
					WA
				}
			}
		}

		if (!containsC)
		{
			WA
		}

		else
			cout << "AC" << endl;

	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}