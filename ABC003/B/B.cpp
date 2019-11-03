#include <iostream>
#include <set>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define SZ(x) ((int)(x).size())

set<char> atcoder {'a', 't', 'c', 'o', 'd', 'e', 'r'};
string s, t;
inline void lose(){ cout << "You will lose" << endl; }

int main()
{
	cin >> s >> t;
	
	REP(i, SZ(s))
	{
		if (s[i] == t[i])
			continue;

		if (s[i] != '@' && t[i] != '@')
		{
			lose();
			return 0;
		}

		if (s[i] == '@')
		{
			if (!atcoder.count(t[i]))
			{
				lose();
				return 0;
			}
		}
		else if (!atcoder.count(s[i]))
		{
			lose();
			return 0;
		}

	}

	cout << "You can win" << endl;
}
