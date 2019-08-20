#include <string>
#include <iostream>

using namespace std;

class A {
	int a, b, c;

public:
	void solve()
	{
		cin >> a >> b >> c;
		if ((b - a) == (c - b)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
};

class B {
	string O, E;

public:
	void solve()
	{
		cin >> O >> E;

		for (size_t i{ 0 }; i < E.length(); i++)
		{
			cout << O[i] << E[i];
		}

		if (E.length() != O.length())
			cout << O.back();

		cout << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}