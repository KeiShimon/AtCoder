#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

class C {
	int N;
	vector<int> a;
public:
	void solve()
	{
		int ans;
		int tot = 0;

		for (int i{ 0 }; i < N + 1; i++)
			tot += abs(a[i + 1] - a[i]);

		for (int giveUp{ 1 }; giveUp <= N; giveUp++)
		{
			ans = tot - abs(a[giveUp + 1] - a[giveUp]) - abs(a[giveUp] - a[giveUp - 1]) + abs(a[giveUp + 1] - a[giveUp - 1]);
			cout << ans << endl;
		}

	}

	C() 
	{
		cin >> N;
		a.resize(N + 2);
		a[0] = a[N + 1] = 0;
		for (int i{ 0 }; i < N; i++)
			cin >> a[i + 1];
	}
};

//
//int main()
//{
//	C solution;
//	solution.solve();
//
//	return 0;
//}