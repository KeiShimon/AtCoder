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

inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

int main()
{
	string s; cin >> s;

	while (!s.empty())
	{
		int n = s.size();
		if (s.back() == 'u' || s.back() == 'o' || s.back() == 'k')
			s.pop_back();
		else if (n >= 2 && s[n - 2] == 'c' && s[n - 1] == 'h')
			s.pop_back(), s.pop_back();
		else
			break;
	}

	if (s.empty())
		YES();
	else
		NO();
}
