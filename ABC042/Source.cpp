#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A {
	int a;
	int ans{ 17 };

public:
	void solve()
	{
		for (int i{ 0 }; i < 3; i++)
		{
			cin >> a;
			
			if (a != 5 && a != 7) break;
			else ans -= a;
		}

		if (ans == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

};

class B {
	vector<string> S;
	int N, L;

public:
	void solve()
	{
		cin >> N >> L;
		S.resize(N);
		for (int i{ 0 }; i < N; i++) cin >> S[i];

		sort(S.begin(), S.end());
		
		for (int i{ 0 }; i < N; i++) cout << S[i];
		cout << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}