#include <iostream>

using namespace std;

int n, s, t, w;

int main()
{
	int ans = 0;
	int d = 1;
	cin >> n >> s >> t;

	for (int d = 0; d < n; ++d)
	{
		int a; cin >> a; w += a;

		if (s <= w && w <= t)
			++ans;
	}

	cout << ans << endl;
}
