#include <algorithm>
#include <iostream>
#include <vector>

#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

void init();
int rec(int x);

int n;
vector<int> opt, memo;
const int inf = 1 << 25;

int main()
{
	init();

	cout << rec(n) << endl;
}

void init()
{
	cin >> n;

	memo.resize(n + 1, inf);
	memo[0] = 0;

	int x = 1;
	opt.PB(x);

	x = 6;
	while (x <= n)
	{
		opt.PB(x);
		x *= 6;
	}

	x = 9;
	while (x <= n)
	{
		opt.PB(x);
		x *= 9;
	}

	sort(ALL(opt), greater<>());
}

int rec(int x)
{
	if (memo[x] < inf)
		return memo[x];

	int ret = inf;

	for (int y : opt)
		if (x >= y)
			ret = min(ret, 1 + rec(x - y));

	return memo[x] = ret;
}
