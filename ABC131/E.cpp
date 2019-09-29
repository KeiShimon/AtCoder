#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> Vi;
typedef vector<vector<int>> VVi;
typedef pair<int, int> pii;

int n, k;

void init()
{
	cin >> n >> k;
}


int main()
{
	init();

	int lim = (n - 1) * (n - 2) / 2;
	if (k > lim)
	{
		cout << -1 << endl;
		return 0;
	}

	vector<pii> edges, candidates;

	REP(i, n - 1)
		edges.emplace_back(pii(i + 1, n));

	REP(i, n - 2)
		for(int j = i + 1; j < n - 1; ++j)
			candidates.emplace_back(pii(i + 1, j + 1));

	int cur = lim;
	int i = 0;
	for (; cur > k; --cur)
	{
		edges.emplace_back(candidates[i++]);		
	}

	cout << edges.size() << endl;
	for (auto edge : edges)
	{
		cout << edge.first << " " << edge.second << endl;
	}

}
