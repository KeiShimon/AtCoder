#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }


class C {
	int N, X;
public:
	void solve()
	{
		vector<int> dx(N);
		int ans, x;
		cin >> x;
		ans = abs(x - X);
		for (int i{ 1 }; i < N; i++)
		{
			cin >> x;
			ans = gcd(ans, abs(x - X));

			if (ans == 1) break;
		}

		cout << ans << endl;
	}
	
	C()
	{
		cin >> N >> X;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}