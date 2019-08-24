#include <iostream>
#include <string>

using namespace std;

class B {
	string s;
public:
	void solve()
	{
		cin >> s;

		do
		{
			s.pop_back();
			s.pop_back();
		} while (s.substr(0, s.size() / 2).compare(s.substr(s.size() / 2)) != 0);

		cout << s.size() << endl;
	}

};


int main()
{
	B solution;
	solution.solve();

	return 0;
}