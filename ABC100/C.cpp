#include <iostream>

using namespace std;

class C {
	int N;
public:
	void solve()
	{
		int ans{ 0 };
		int a;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> a;
			while (!(a & 1))
			{
				ans++;
				a >>= 1;
			}
		}

		cout << ans << endl;
	}

	C()
	{
		cin >> N;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}