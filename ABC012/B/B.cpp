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

int n;

int main()
{
	cin >> n;

	int h, m, s;

	h = n / 3600;
	n -= h * 3600;

	m = n / 60;
	s = n % 60;

	cout << setw(2) << setfill('0') << h << ":";
	cout << setw(2) << setfill('0') << m << ":" ;
	cout << setw(2) << setfill('0') << s << endl;
}
