#include <iostream>

using namespace std;

class B {
	int N;
public:
	void solve()
	{

		if (!(N & 0b11))
		{
			cout << "Yes" << endl;
			return;
		}

		while (N >= 7)
		{
			N -= 7;
			if (!(N & 0b11))
			{
				cout << "Yes" << endl;
				return;
			}
		}
		
		cout << "No" << endl;
	}

	B() { cin >> N; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}