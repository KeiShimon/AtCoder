#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


class D {
	vvi g;
	int n;
	vi col;
	vi from;
	deque<int> sf;
public:
	D()
	{
		cin >> n;
		g.resize(n);
		from.resize(n, -1);
		col.resize(n, -1);

		REP(i, n - 1)
		{
			int a, b;
			cin >> a >> b;
			a--; b--;
			g[a].PB(b);
			g[b].PB(a);
		}
	}

	void dfs_path(int v, int frm)
	{

		from[v] = frm;

		if (v == n - 1)
			return;

		for (int nxt : g[v])
			if (nxt != frm)
				dfs_path(nxt, v);
	}


	void dfs(int v, bool p, int frm)
	{
		col[v] = p;

		for (int nxt : g[v])
			if (nxt != frm && col[nxt] != (!p) )
				dfs(nxt, p, v);
	}

	void solve()
	{
		dfs_path(0, -1);

		int v = n - 1;
		while (v != 0)
		{
			sf.push_front(v);
			v = from[v];

		}
		sf.push_front(0);

		bool p = false;
		while (!sf.empty())
		{
			if (!p)
			{
				col[sf.front()] = p;
				sf.pop_front();
			}

			else
			{
				col[sf.back()] = p;
				sf.pop_back();
			}

			p = !p;
		}


		dfs(0, 0, -1);
		dfs(n - 1, 1, -1);

		int cnt0, cnt1;
		cnt0 = cnt1 = 0;

		REP(i, n)
		{
			if (col[i] == 0)
				++cnt0;
			else
				++cnt1;
		}

		if (cnt0 > cnt1)
			cout << "Fennec" << endl;
		else
			cout << "Snuke" << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}