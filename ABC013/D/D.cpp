#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

typedef vector<int> Vi;
typedef vector<vector<int> > VVi;

inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

int n, m, d;
VVi res;
Vi edges;

int main()
{

	cin >> n >> m >> d;

	res.resize(32, Vi(n + 1));
	REPC(i, n) res[0][i] = res[1][i] = i;

	edges.resize(m);
	RREP(i, m) cin >> edges[i];
	for (int a : edges)
		swap(res[1][a], res[1][a + 1]);

	for (int t = 2; t <= d; t <<= 1)
	{
		int i = 0;
		for (int tmp = t; tmp; tmp >>= 1)
			++i;

		REP1C(j, n)
			res[i][j] = res[i - 1][res[i - 1][j]];
	}

	REP1C(x, n)
	{
		int ans = x;

		REP(bit, 32)
			if (d & (1 << bit))
				ans = res[bit + 1][ans];

		cout << ans << endl;
	}
}
