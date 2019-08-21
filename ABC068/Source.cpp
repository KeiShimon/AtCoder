#include <iostream>


using namespace std;


class A {
	int N;

public:
	void solve()
	{
		cin >> N;

		cout << "ABC" << N << endl;
	}
};


class B {
	int N;

public:
	void solve()
	{
		cin >> N;

		int ans{ 1 };

		for (; ans <= N; ans <<= 1);

		cout << ans / 2 << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}