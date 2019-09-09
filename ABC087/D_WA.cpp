#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


#define FAIL cout << "No" << endl; return false;

class D {
	int n, m;
	vector<int> pos;
	vector<vector<pii>> g;
	const int null{ 2000000000 };
	int rightmost{ 0 };

public:
	D()
	{
		cin >> n >> m;
		g.resize(n + 1);
		pos.resize(n + 1, null);
		
		int u, v, d;
		REP(i, m)
		{
			cin >> u >> v >> d;
			g[u].emplace_back(MP(v, d));
		}
	}

	bool dfs(int node, int frm , int cost)
	{

		//cout << "visiting " << node << endl;

		// loop detection
		if (pos[node] == -null)
			return false;

		if (pos[node] != null)
		{
			if (pos[node] != frm + cost)
				return false;
			else
				return true;
		}
		else if (g[node].empty())
		{
			if (pos[node] == null)
			{
				if (frm == -null)
					pos[node] = rightmost;
				else
					pos[node] = frm + cost;
			}
			return true;
		}
		else
		{
			if (frm != -null)
				pos[node] = frm + cost;
			else
				pos[node] = -null;
		}


		REP(i, SZ(g[node]))
		{
			int to{ g[node][i].first };
			int d{ g[node][i].second };

			if (!dfs(to, pos[node], d))
				return false;

			if (pos[node] == -null)
			{
				pos[node] = pos[to] - d;
			}
			else if (pos[node] + d != pos[to])
				return false;

		}

		return true;
	}

	void solve()
	{

		REP(node, n + 1)
		{
			if (!g[node].empty() && pos[node] == null)
			{
				if (!dfs(node, -null, 0))
				{
					cout << "No" << endl;
					return;
				}
			}
		}

		cout << "Yes" << endl;

	}

	void debug()
	{
		REP(i, SZ(pos))
			cout << i << " is at " << pos[i] << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}