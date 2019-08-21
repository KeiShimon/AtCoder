#include <iostream>
#include <string>
#include <numeric>
#include <vector>

using namespace std;


class A {
	int A, B, X;

public:
	void solve()
	{
		cin >> A >> B >> X;

		if (X >= A && X <= (A + B)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
};



class B {
	int N, M, X;
	vector<int> vec;

public:
	void solve()
	{
		cin >> N >> M >> X;
		vec.resize(N + 1);

		int a;
		for (int i{ 0 }; i < M; i++)
		{
			cin >> a;
			vec[a] = 1;
		}

		int costLeft{ accumulate(vec.begin(), vec.begin() + X, 0) };
		int costRight{ accumulate(vec.begin() + X, vec.end(), 0) };

		cout << ((costLeft < costRight) ? costLeft : costRight) << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}