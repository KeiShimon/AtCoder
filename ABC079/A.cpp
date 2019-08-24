#include <iostream>
#include <string>

using namespace std;

class A {
	int n;
	string ns;
public:
	void solve()
	{
		cin >> n;
		ns = to_string(n);

		if (ns[1] == ns[2])
		{
			if ((ns[0] == ns[1]) || (ns[3] == ns[1])) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}