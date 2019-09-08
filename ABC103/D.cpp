#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t int64;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;

class D {
	int n_islands, m;
	int n_bridges{ 0 };
	vector<vector<int>> banned;
	vector<int> lands;

public:
	D()
	{
		cin >> n_islands >> m;
		banned.resize(n_islands + 1);
		lands.resize(n_islands + 1, -1);

		int a, b;
		REP(i, m)
		{
			cin >> a >> b;
			banned[a].PB(b);
			banned[b].PB(a);
		}
	}

	int root(int a)
	{
		if (lands[a] < 0)
			return a;

		lands[a] = root(lands[a]);
		return lands[a];
	}

	void add(int a, int b)
	{
		bool canAdd{ true };
		int union_adjacent{ root(a) };

		for (int c : banned[b])
		{
			if (root(c) == union_adjacent)
			{
				canAdd = false;
				break;
			}
		}

		if (canAdd)
		{
			++n_bridges;
			lands[b] = union_adjacent;
		}

	}

	void solve()
	{

		for (int a{ 1 }; a < n_islands; a++)
			add(a, a + 1);

		cout << n_islands - 1 - n_bridges;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}