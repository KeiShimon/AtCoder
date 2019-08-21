#include <iostream>
#include <string>
#include <vector>

using namespace std;


class A {
	int a, b, money;

public:
	void solve()
	{
		cin >> a >> b >> money;

		if (a > b) cout << money / b << endl;
		else cout << money / a << endl;

	}
};


class B {
	int N, Q;
	int arr[100]{ 0 };

public:
	void solve()
	{
		cin >> N >> Q;

		int L, R, t;
		for (int i{ 0 }; i < Q; i++)
		{
			cin >> L >> R >> t;
			for (int j{ L - 1 }; j < R; j++) arr[j] = t;
		}

		for (int i{ 0 }; i < N; i++) cout << arr[i] << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}