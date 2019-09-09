#include <iostream>

using namespace std;

class B {
	int n, d, x;
public:
	void solve()
	{
		int a;
		int day;
		int ans{ x };

		for (int i{ 0 }; i < n; i++)
		{
			cin >> a;
			day = 1;

			while (day <= d)
			{
				ans++;
				day += a;
			}
		}

		cout << ans << endl;
	}

	B()
	{
		cin >> n >> d >> x;
	}
};


//int main()
//{
//	B solution;
//	solution.solve();
//
//	return 0;
//}