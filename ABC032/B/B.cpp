#include <iostream>
#include <set>
#include <string>

using namespace std;

string s;
int k, ns;
set<string> ss;

int main()
{
	cin >> s >> k;
	ns = s.size();

	for (int l = 0; l + k <= ns; ++l)
			ss.insert(s.substr(l, k));

	cout << ss.size() << endl;
}
