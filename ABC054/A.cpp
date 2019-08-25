#include <iostream>

using namespace std;

#define ALICE cout << "Alice" << endl
#define BOB cout << "Bob" << endl
#define DRAW cout << "Draw" << endl


class A {
	int a, b;
public:
	void solve()
	{
		if (a != b)
		{
			if (a != 1)
			{
				if (b != 1)
				{
					if (a > b) ALICE;
					else BOB;
				}
				else BOB;
			}
			else ALICE;
		}
		else DRAW;
	}

	A() { cin >> a >> b; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}