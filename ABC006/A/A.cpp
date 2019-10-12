#include <iostream>
#include <string>

using namespace std;

int n;

int main()
{
	cin >> n;

	if (!(n % 3)) cout << "YES" << endl;
	else if (to_string(n).find("3") == string::npos) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}