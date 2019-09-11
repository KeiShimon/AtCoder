#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;


class B {
	int N, d;
	unordered_set <int> s;

public:
	void solve()
	{
		cin >> N;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> d;
			s.insert(d);
		}

		cout << s.size() << endl;
	}
};


int main()
{
	B solution;
	solution.solve();
	return 0;
}