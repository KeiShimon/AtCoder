#include <unordered_set>
#include <iostream>
#include <string>


using namespace std;

class A {
	string S;

public:
	void solve()
	{
		cin >> S;

		cout << "2018" << S.substr(4) << endl;
	}
};


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
	A solution;
	solution.solve();
	return 0;
}