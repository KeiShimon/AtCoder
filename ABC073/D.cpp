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

#include <queue>

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
	int n, m, r;
	vector<vector<P>> g;
	vvll d;
	vi vis;
public:
	D()
	{
		cin >> n >> m >> r;

		g.resize(n + 1);
		d.resize(n + 1, vll(n + 1, LLMAX));
		vis.resize(r);

		REP(i, r)
		{
			cin >> vis[i];
		}
		sort(ALL(vis));

		REP(i, m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			g[a].PB(MP(b,c));
			g[b].PB(MP(a,c));
		}

		REP(i, n + 1)
			sort(ALL(g[i]), [](const pii& left, const pii& right) { return left.second < right.second; });

	}

	void init()
	{
		REP(i, r)
		{
			int org = vis[i];
			vector<bool> done(n + 1, 0);
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;

			que.emplace(MP(0LL, org));

			while (!que.empty())
			{
				ll curd = que.top().first;
				int cur = que.top().second;
				que.pop();
				done[cur] = true;

				REP(j, SZ(g[cur]))
				{
					int nxt = g[cur][j].first;

					if (!done[nxt])
					{
						ll cst = g[cur][j].second;
						if (chmin(d[org][nxt], curd + cst))
							que.emplace(MP(d[org][nxt], nxt));
					}
				}
			}
		}
	}

	void solve()
	{
		init();

		ll ans = LLMAX;

		do
		{
			ll tmp = 0;

			REP(i, r - 1)
			{
				tmp += (ll)d[vis[i]][vis[i + 1]];
			}
			
			chmin(ans, tmp);

		} while (next_permutation(ALL(vis)));

		cout << ans << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}