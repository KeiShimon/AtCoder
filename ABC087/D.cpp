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
	int n, m;
	vector<vector<pii>> g;
	vi loc;
	int nul{ INTMAX };
public:
	D()
	{
		cin >> n >> m;
		g.resize(n + 1);
		loc.resize(n + 1, nul);

		REP(i, m)
		{
			int l, r, d;
			cin >> l >> r >> d;

			g[l].emplace_back(MP(r, d));
			g[r].emplace_back(MP(l, -d));
		}

	}

	void solve()
	{

		REP1C(i, n)
		{

			if (loc[i] == nul)
			{
				loc[i] = 0;
				deque<int> que;
				que.PB(i);

				while (!que.empty())
				{
					int v = que.front(); que.pop_front();

					REP(i, SZ(g[v]))
					{
						int nxt = g[v][i].first;
						int c = g[v][i].second;

						if (loc[nxt] == nul)
						{
							loc[nxt] = loc[v] + c;
							que.PB(nxt);
						}
						else if (loc[nxt] != loc[v] + c)
						{
							cout << "No" << endl;
							return;
						}
					}
				}
			}
		}

		cout << "Yes" << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}

