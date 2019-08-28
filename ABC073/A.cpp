#include <iostream>

using namespace std;

class A {
	int N;
public:
	void solve()
	{
		if (N % 10 == 9 || ( N / 10 % 10 == 9)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	A() { cin >> N; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}