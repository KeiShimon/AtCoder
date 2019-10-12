#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	int tmp = n, c = 0;

	for (; tmp; tmp >>= 1)
		c += tmp & 1;
	cout << c << endl;

	int b = 1;
	while (n)
	{
		if (n & 1)
			cout << b << endl;
		n >>= 1;
		b <<= 1;
	}
}
