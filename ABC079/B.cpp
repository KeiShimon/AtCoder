#include <iostream>

using namespace std;

class B {
	int n;
	int64_t a{ 2 }, b{ 1 }, tmp;
public:
	void solve()
	{
		cin >> n;
		if (n == 1) cout << 1 << endl;
		else 
		{
			for (int i{ 2 }; i <= n; i++)
			{
				tmp = a + b;
				a = b;
				b = tmp;
			}

			cout << tmp << endl;
		}
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}