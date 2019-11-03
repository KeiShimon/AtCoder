#include <iostream>

using namespace std;

int n;
string s;

int main()
{
	cin >> n >> s;

	char last = 'A';
	int ans = 0;

	for (char c : s)
	{
		if (c == last)
			continue;

		last = c;
		++ans;
	}

	cout << ans << endl;
}
