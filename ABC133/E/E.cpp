#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

const int MOD = 1000000007;

void init();
void treeDP(int v);

int n, k;
vector<vector<int>> g;
vector<int> vval, vcnt;

int main()
{
	init();

	treeDP(0);

	long long ans = 1;
	REP(i, n)
		ans = ans * vval[i] % MOD;

	cout << ans << endl;
}

void init()
{
	cin >> n >> k;
	g.resize(n);

	REP(_i, n - 1)
	{
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vval.resize(n, -1);
	vcnt.resize(n, 0);
}

void treeDP(int v)
{
	int c = k;
	int fixed = 0;
	for (int u : g[v])
		if (vval[u] != -1)
		{
			c -= vcnt[u];
			++fixed;
		}

	vval[v] = max(0, c);
	vcnt[v] = 1 + fixed;

	for (int u : g[v])
		if (vval[u] == -1)
		{
			treeDP(u);
			++vcnt[v];
		}
}

//// done E in 50mins on 30th Sep, 2019 ////
