#include <iostream>
#include <string>

using namespace std;

class A {
	string s;
public:
	void solve()
	{
		if ((s.find('a') != string::npos) && (s.find('b') != string::npos) && (s.find('c') != string::npos))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
	A() { cin >> s; }
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}