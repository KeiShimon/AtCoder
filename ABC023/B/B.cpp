#include <iostream>

using namespace std;

int main()
{
	int n; 
	int ans = 0;
	string s, tmp("b");

	cin >> n >> s;

	while (tmp.size() < n)
	{
		++ans;

		if (ans % 3 == 1)
		{
			tmp = "a" + tmp + "c";
		}
		else if (ans % 3 == 2)
		{
			tmp = "c" + tmp + "a";
		}
		else
		{
			tmp = "b" + tmp + "b";
		}
	}

	if (tmp == s)
		cout << ans << endl;
	else
		cout << -1 << endl;
}
