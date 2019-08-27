#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class C {
	int N, M, ans{ 0 };
	vector<int> X;
public:
	void solve()
	{
		if (M > 1 && M > N)
		{
			for (int i{ 0 }; i < M; i++)
				cin >> X[i];

			sort(X.begin(), X.end());

			vector<int> dX(M - 1);
			for (int i{ 0 }; i < M - 1; i++)
				dX[i] = X[i + 1] - X[i];

			if (N > 1)
				sort(dX.begin(), dX.end());

			ans = accumulate(dX.begin(), dX.end() - (N - 1), 0);
		}

		cout << ans << endl;
	}

	C() { cin >> N >> M; X.resize(M); }
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}