#include <algorithm>
#include <cmath>
#include <deque>
#include <limits.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

int x, y;
int dir[2];
char dig[9][9];
string w, otp;

void move(int& x, int& y, int* dir)
{
	int dx = dir[0];
	int dy = dir[1];

	if (x + dx < 0)
		dir[0] = 1;
	else if (x + dx >= 9)
		dir[0] = -1;

	if (y + dy < 0)
		dir[1] = 1;
	else if (y + dy >= 9)
		dir[1] = -1;

	dx = dir[0]; dy = dir[1];
	x += dx;
	y += dy;
}

int main()
{
	cin >> x >> y >> w;
	--x; --y;
	REP(i, 9) REP(j, 9) cin >> dig[i][j];

	if (w == "R")
		dir[0] = 1, dir[1] = 0;
	else if (w == "L")
		dir[0] = -1, dir[1] = 0;
	else if (w == "U")
		dir[0] = 0, dir[1] = -1;
	else if (w == "D")
		dir[0] = 0, dir[1] = 1;
	else if (w == "RU")
		dir[0] = 1, dir[1] = -1;
	else if (w == "RD")
		dir[0] = 1, dir[1] = 1;
	else if (w == "LU")
		dir[0] = -1, dir[1] = -1;
	else if (w == "LD")
		dir[0] = -1, dir[1] = 1;

	REP(_i, 4)
	{
		otp.push_back(dig[y][x]);
		move(x, y, dir);
	}

	cout << otp << endl;
}
