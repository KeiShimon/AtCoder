#include <iostream>
#include <string>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

const string tak[]{ "TAKAHASHIKUN", "Takahashikun", "takahashikun" };
int n;

int main()
{
	cin >> n;
	int ans = 0;
	REP(_i, n)
	{
		string s;
		cin >> s;

		if (s.back() == '.')
			s.pop_back();

		if (s == tak[0] || s == tak[1] || s == tak[2])
			++ans;
	}

	cout << ans << endl;
}
