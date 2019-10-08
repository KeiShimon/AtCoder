#include <iostream>
#include <string>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;


int main()
{
	int ans = 0;
	REP(_i, 12)
	{
		string s; cin >> s;
		if (s.find("r") != string::npos)
			++ans;
	}
	cout << ans << endl;
}
