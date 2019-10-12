#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)

int m, k;

int main()
{
	cin >> m >> k;

	if (!m)
	{
		if (!k)
			cout << "0 0" << endl;
		else
			cout << -1 << endl;
		return 0;
	}

	if (m == 1)
	{
		if (k == 0)
			cout << "0 0 1 1" << endl;
		else
			cout << -1 << endl;
		return 0;
	}

	if (k >= (1 << m))
	{
		cout << -1 << endl;
		return 0;
	}

	REP(i, 1 << m)
		if (i != k)
			cout << i << " ";
	cout << k << " ";

	RREP(i, 1 << m)
		if (i != k)
			cout << i << " ";
	cout << k << endl;

}
