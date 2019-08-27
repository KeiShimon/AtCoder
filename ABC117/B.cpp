#include <iostream>
#include <numeric>

using namespace std;

class B {
	int N;
	int L[100]{ 0 };
public:
	void solve()
	{
		int maximum{ 0 };

		for (int i{ 0 }; i < N; i++)
		{
			cin >> L[i];
			if (maximum < L[i]) maximum = L[i];
		}

		int sumExcludeMax{ accumulate(L, L + 100, 0) - maximum };

		if (maximum < sumExcludeMax) cout << "Yes" << endl;
		else cout << "No" << endl;

	}

	B() { cin >> N; }
};

int main()
{
	B solution;
	solution.solve();

	return 0;
}