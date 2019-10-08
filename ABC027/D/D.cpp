#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> Vi;

int main()
{
	string s; cin >> s;
	int n = s.size();
	Vi imos(n, 0);

	for (int i = 1; i < n; ++i)
	{
		if (s[i] == '+')
		{
			imos[i]++;
		}
		else if (s[i] == '-')
		{
			imos[i]--;
		}
	}

	for (int i = n - 2; i >= 0; --i)
		imos[i] += imos[i + 1];

	Vi v;

	for (int i = 0; i < n; ++i)
		if (s[i] == 'M')
			v.push_back(imos[i]);

	sort(v.begin(), v.end(), greater<>());

	int ans = accumulate(v.begin(), v.begin() + (int)v.size() / 2, 0);
	ans -= accumulate(v.begin() + (int)v.size() / 2, v.end(), 0);

	cout << ans << endl;
}
