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

int t, n, m;
int make[101], customer[101];

void init();

int main()
{
	init();

	queue<int> que;
	int now;
	int i = 0;
	
	REP(j, m)
	{
		now = customer[j];

		while (!que.empty() && que.front() + t < now)
			que.pop();

		while (i < n && make[i] <= now)
			que.push(make[i++]);

		if (que.empty())
		{
			cout << "no" << endl;
			return 0;
		}

		que.pop();
	}

	cout << "yes" << endl;
}


void init()
{
	cin >> t >> n;

	REP(i, n)
		cin >> make[i];
	
	cin >> m;
	REP(i, m)
		cin >> customer[i];
}
