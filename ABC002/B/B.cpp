#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	ostringstream oss;
	for (char c : s)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			continue;
		oss << c;
	}

	cout << oss.str() << endl;
}
