#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++)

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;
typedef double dbl;
typedef vector<bool> Vb;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<string> Vs;
typedef vector<vector<int> > VVi;
typedef vector<vector<ll> > VVl;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

typedef pair<ll, int> P;
using G = vector<vector<P> >;

void init();
void Dijkstra(int org);

G g;
int n, m, q;
ll l;
VVi dijkstra_results;
Vl d;
VVl matrix;

const int inf = 1 << 28;
const ll linf = 1LL << 60;

void init()
{
	cin >> n >> m >> l;
	g.resize(n);
	dijkstra_results.resize(n, Vi(n, -1));
	matrix.resize(n, Vl(n, linf));

	REP(_i, m)
	{
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;

		if (c <= l)
		{
			g[a].push_back(P(c, b));
			g[b].push_back(P(c, a));
			matrix[a][b] = c;
			matrix[b][a] = c;
		}
	}
}

int main()
{
	init();
	REP(i, n) Dijkstra(i);

	cin >> q;
	REP(_i, q)
	{
		int a, b;
		cin >> a >> b; --a; --b;

		if (dijkstra_results[a][b] == -1)
		{
			cout << -1 << endl;
			continue;
		}

		Vi path{ b };
		while (dijkstra_results[a][b] != -1)
		{
			path.push_back(dijkstra_results[a][b]);
			b = dijkstra_results[a][b];
		}
		reverse(ALL(path));

		ll fuel = l;
		int ans = 0;
		REP(i, path.size() - 1)
		{
			ll c = matrix[path[i]][path[i + 1]];
			if (fuel >= c)
			{
				fuel -= c;
			}
			else
			{
				fuel = l - c;
				++ans;
			}
		}

		cout << ans << endl;
	}

}

void Dijkstra(int org)
{
	vector<bool> done(n, false);
	d.assign(n, linf);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(make_pair(0, org));

	while (!que.empty())
	{
		auto c = que.top().first;
		int v = que.top().second;
		que.pop();
		done[v] = true;

		if (c > d[v])
			continue;

		for (P p : g[v])
			if (!done[p.second] && chmin(d[p.second], c + p.first))
			{
				que.push(P(d[p.second], p.second));
				dijkstra_results[org][p.second] = v;
			}
	}
}