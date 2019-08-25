#include <iostream>
#include <vector>

using namespace std;

class B {
	int N;
	vector<string> field;
public:
	void solve()
	{
		field.resize(N);
		for (int i{ 0 }; i < N; i++)
			cin >> field[i];

		for (int i{ 0 }; i < N; i++)
		{
			for (int j{ 0 }; j < N; j++)
			{
				cout << field[N - j - 1][i];
			}
			cout << endl;
		}
	}
	B() { cin >> N; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}