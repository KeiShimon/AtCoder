#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <utility>
#include <vector>
#include <deque>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i > 0; i--)
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


class E {
	static const int MAX_N = 1001;
	static const int MAX_V = MAX_N * (MAX_N - 1) / 2;
	int id[MAX_N][MAX_N];
	int n;
	int n_vertices{ 0 };
	vector<vector<int>> a;
	vector<int> G[MAX_V];
	int visited[MAX_V];
	int distance[MAX_V];

	int getID(int i, int j) { return (i > j) ? id[j][i] : id[i][j]; }

	int dfs(int v)
	{
		if (visited[v])
			return (visited[v] == 1) ? -1: distance[v];
		visited[v]++;

		distance[v] = 1;
		for (int u : G[v])
		{
			int depth = dfs(u);
			if (depth == -1)
				return -1;
			distance[v] = max(distance[v], depth + 1);
		}

		visited[v]++;
		return distance[v];
	}

public:
	E()
	{
		memset(visited, 0, sizeof visited);
		cin >> n;
		a.resize(n, vector<int>(n - 1));

		REP(i, n)
		{
			REP(j, n - 1)
			{
				cin >> a[i][j];
				--a[i][j];
			}
		}

		REP(i, n)
			REP(j, n)
		{
			if (i < j)
				id[i][j] = n_vertices++;
		}

		REP(i, n)
		{
			REP(j, n - 1)
				a[i][j] = getID(i, a[i][j]);

			REP(j, n - 2)
				G[a[i][j]].PB(a[i][j + 1]);
		}
	}

	void solve()
	{
		int ans = 0;
		REP(i, n_vertices)
		{
			int depth = dfs(i);
			if (depth == -1)
			{
				cout << "-1" << endl;
				return;
			}
			ans = max(ans, depth);
		}
		cout << ans << endl;
	}
};


int main()
{
	E solution;
	solution.solve();

	return 0;
}
