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

inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

int a, b;

int main()
{
	cin >> a >> b;
	swap(a, b);

	cout << a << " " << b << endl;
}
