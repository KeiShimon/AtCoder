#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int n; cin >> n;
	string n_s = to_string(n);
	int dig = n_s.size();
	n_s = "";
	while (dig < 9)
	{
		n_s += "0";
		dig++;
	}
	n_s += to_string(n);
		
	ostringstream leading("");
	
	int ans = 0;
	for (int p = 8; p >= 0; --p)
	{
		if (leading.str() != "")
		{
			ans += stoi(leading.str()) * pow(10, p);
			leading << n_s[8 - p];
		}
		else if (n_s[8 - p] != '0')
			leading << n_s[8 - p];

		if (n_s[8 - p] > '1')
			ans += pow(10, p);
		else if (n_s[8 - p] == '1')
			ans += n % (int)pow(10, p) + 1;
	}

	cout << ans << endl;
}