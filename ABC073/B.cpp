#include <iostream>

using namespace std;

class B {
	int N;
public:
	void solve()
	{
		int left, right;
		int ans{ 0 };
		for (int i{ 0 }; i < N; i++)
		{
			cin >> left >> right;
			ans += (right - left + 1);
		}

		cout << ans << endl;
	}

	B() { cin >> N; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}