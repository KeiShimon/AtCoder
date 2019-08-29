#include <iostream>

using namespace std;

class B {
	int N;
public:
	void solve()
	{
		if (!(N % 111)) cout << N << endl;
		else cout << ((1 + N / 111) * 111) << endl;
	}

	B()
	{
		cin >> N;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}