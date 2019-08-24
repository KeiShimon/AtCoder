#include <iostream>
#include <cmath>

using namespace std;

class B {
	int N, ans;
	double A, T, H;
public:
	void solve()
	{
		cin >> N >> T >> A;

		double minDiff{ 999999 };
		double tmpDiff;

		for (int i{ 1 }; i <= N; i++)
		{
			cin >> H;
			tmpDiff = abs((A - (T - 0.006 * H)));
			if (tmpDiff < minDiff)
			{
				ans = i;
				minDiff = tmpDiff;
			}

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