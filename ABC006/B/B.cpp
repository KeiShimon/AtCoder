#include <iostream>

using namespace std;
int n;
int a{ 0 }, b{ 0 }, c{ 1 }, tmp;

int main()
{
	cin >> n;

	if (n <= 2) cout << 0 << endl;
	else if (n == 3) cout << 1 << endl;
	else
	{
		for (int i{ 4 }; i <= n; i++)
		{
			tmp = (a + b + c) % 10007;
			a = b;
			b = c;
			c = tmp;
		}
		cout << tmp << endl;
	}

	return 0;
}