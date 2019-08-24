#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class B {
	string S;
	int N;
public:
	void solve()
	{
		cin >> S >> N;
		
		int L, R;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> L >> R;
			reverse(S.begin() + L - 1, S.begin() + R);
		}

		cout << S << endl;

	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}