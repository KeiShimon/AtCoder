#include <iostream>

using namespace std;

#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

int main()
{
	int N; cin >> N;

	REP1C(i, 9)
		REP1C(j, 9)
	{
		if (i * j == N)
		{
			Yes();
			return 0;
		}
	}

	No();
}
