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

int main()
{
	int a, b, c; cin >> a >> b >> c;

	if (c == a + b && c == a - b)
	{
		cout << "?" << endl;
		return 0;
	}

	if (c == a + b)
		cout << "+" << endl;
	else if (c == a - b)
		cout << "-" << endl;
	else
		cout << "!" << endl;
}
