#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> Vi;

void init();
void bfs(int org, vector<int>& d);

int n;
Vi opt, dp;

int main()
{
	init();

	bfs(0, dp);

	cout << dp[n] << endl;
}

void init()
{
	cin >> n;

	dp.resize(n + 1, -1);

	opt.PB(1);
	for (int x = 6; x <= n; x *= 6)
		opt.PB(x);
	for (int x = 9; x <= n; x *= 9)
		opt.PB(x);

	sort(ALL(opt), greater<>());
}


void bfs(int org, vector<int>& d)
{
	d[org] = 0;
	queue<int> que;
	que.push(org);

	while (!que.empty())
	{
		int v = que.front();
		que.pop();

		for (int x : opt)
			if (v + x <= n)
				if (dp[v + x] == -1)
				{
					dp[v + x] = dp[v] + 1;
					que.push(v + x);
				}
	}
}