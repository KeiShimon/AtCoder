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

typedef pair<int, ll> P;

class D {
	int n, q, k;
	vll d;
	vector<vector<P>> g;
	const int nul = INTMAX;
public:
	D()
	{
		cin >> n;
		d.resize(n + 1, nul);
		g.resize(n + 1);

		REP(i, n - 1)
		{
			int a, b;
			ll c;
			cin >> a >> b >> c;

			g[a].emplace_back(MP(b, c));
			g[b].emplace_back(MP(a, c));

		}

		cin >> q >> k;

	}

	void init()
	{
		d[k] = 0;

		deque<int> que;
		que.PB(k);

		while (!que.empty())
		{
			int cur = que.front(); que.pop_front();

			REP(i, SZ(g[cur]))
			{
				int nxt = g[cur][i].first;
				ll c = g[cur][i].second;

				if (d[nxt] == nul)
				{
					d[nxt] = d[cur] + c;
					que.PB(nxt);
				}
			}
		}

	}

	void solve()
	{

		init();

		//REP(i, n + 1)
		//	cout << d[i] << " ";
		//cout << endl;

		REP(i, q)
		{
			int x, y;
			cin >> x >> y;

			cout << d[x] + d[y] << endl;

		}

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}