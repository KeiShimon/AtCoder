#include <iostream>

using namespace std;

class A {
	int N, K;
public:
	void solve()
	{
		if (!(N % K)) cout << 0 << endl;
		else cout << 1 << endl;

	}
	A() { cin >> N >> K; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}