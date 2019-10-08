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

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;


int main()
{
	string s, t;
	cin >> s >> t;
	int n_s = SZ(s), n_t = SZ(t);

	if (n_s > n_t)
		cout << s << endl;
	else
		cout << t << endl;
}
