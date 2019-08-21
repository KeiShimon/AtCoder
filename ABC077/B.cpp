#include <iostream>
#include <cmath>

using namespace std;


class B {
	int N;
public:
	void solve()
	{
		cin >> N;
		int base{ (int)sqrt(N) };
		
		cout << (base * base) << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}