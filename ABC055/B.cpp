#include <iostream>
#include <cmath>

using namespace std;


class B {
	int MOD{ 7 + (int)pow(10, 9) };
	int N;
	int64_t ans{ 1 };
public:
	void solve()
	{
		cin >> N;

		for (int i{ 1 }; i <= N; i++)
		{
			ans *= i;
			ans %= MOD;
		}

		cout << ans << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}