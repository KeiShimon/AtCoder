#include <iostream>
#include <string>


#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

int n;
string s;

void dfs(int d)
{
	if (d == n)
	{
		cout << s << endl;
		return;
	}

	REP(i, 3)
	{
		s[d] = 'a' + i;
		dfs(d + 1);
	}
}

int main()
{
	cin >> n;
	s = string(n, 'a');
	dfs(0);
	
}
