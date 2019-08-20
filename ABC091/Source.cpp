#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class A {
	int a, b, c;

public:
	void solve()
	{
		cin >> a >> b >> c;

		if ((a + b) >= c) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
};


class B {
	int N;
	unordered_map<string, int> um;
	int ans{ 0 };
	string s;

public:
	void solve()
	{
		unordered_map<string, int>::iterator found;
		cin >> N;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> s;
			if ((found = um.find(s)) == um.end())
				um.insert(make_pair(s, 1));
			else found->second += 1;
		}

		cin >> N;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> s;
			if ((found = um.find(s)) != um.end())
				found->second -= 1;
		}

		for (found = um.begin(); found != um.end(); found++)
			ans = max(ans, found->second);

		cout << ans << endl;

	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}