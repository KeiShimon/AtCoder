#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

char c[4][4];

int main()
{
	REP(i, 4)
		REP(j, 4)
		cin >> c[i][j];

	REP(i, 2)
		REP(j, 4)
	{
		char tmp = c[i][j];
		c[i][j] = c[3 - i][3 - j];
		c[3 - i][3 - j] = tmp;
	}

	REP(i, 4)
	{
		cout << c[i][0] << " " << c[i][1] << " " << c[i][2] << " " << c[i][3] << endl;
	}
}
