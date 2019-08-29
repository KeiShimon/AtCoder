#include <iostream>
#include <string.h>

using namespace std;

inline int GETI(const char& c) { return c - 'a'; }
const char UNDEF = 'A';

class C {
	string S, T;
	char coding[26];
	bool used[26];
public:
	void solve()
	{
		bool flag{ true };
		char s, t;

		for (int i{ 0 }; i < S.size(); i++)
		{
			s = S[i];
			t = T[i];

			if (coding[GETI(s)] == UNDEF)
			{
				if (used[GETI(t)])
				{
					flag = false;
					break;
				}
				coding[GETI(s)] = t;
				used[GETI(t)] = true;
			}
			else
			{
				if (coding[GETI(s)] != t)
				{
					flag = false;
					break;
				}
			}
		}

		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	C()
	{
		cin >> S >> T;
		for (int i{ 0 }; i < 26; i++)
		{
			coding[i] = UNDEF;
			used[i] = false;
		}
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}