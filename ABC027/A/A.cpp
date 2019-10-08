#include <iostream>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

int main()
{
	int x = 0;

	REP(_i, 3)
	{
		int y;
		cin >> y;
		x ^= y;
	}

	cout << x << endl;
}
