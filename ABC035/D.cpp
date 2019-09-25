#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
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

const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const int MOD = 1000000007;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


typedef pair<ll, int> P;
template <class Tidx, class Tdist>
void Dijkstra(const Tidx org, const vector<vector<pair<Tdist, Tidx>>>& g, vector<Tdist>& d);

int n, m;
ll t;
const ll inf = 1LL << 60;
vector<vector<P>> g, g_bwd;
vll fwd, bwd, val;

void init()
{
	cin >> n >> m >> t;
	g.resize(n + 1);
	g_bwd.resize(n + 1);
	val.resize(n + 1);

	REP1C(i, n)
		cin >> val[i];

	REP(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;

		g[a].emplace_back(MP(c, b));
		g_bwd[b].emplace_back(MP(c, a));
	}
}

int main()
{
	init();
	Dijkstra(1, g, fwd);
	Dijkstra(1, g_bwd, bwd);

	ll ans = 0;
	REP1C(i, n)
	{
		ll tmp = max((ll)0, t - fwd[i] - bwd[i]) * val[i];
		chmax(ans, tmp);
	}

	cout << ans << endl;
}

template <class Tidx, class Tdist>
void Dijkstra(const Tidx org, const vector<vector<pair<Tdist, Tidx>>>& g, vector<Tdist>& d)
{
	using P = pair<Tdist, Tidx>;

	vector<bool> done(n + 1, false);
	d.assign(n + 1, inf);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(MP((Tdist)0, org));

	while (!que.empty())
	{
		Tdist c = que.top().first;
		Tidx v = que.top().second;
		que.pop();
		done[v] = true;

		for (P p : g[v])
			if (!done[p.second] && chmin(d[p.second], c + p.first))
				que.push(MP(d[p.second], p.second));
	}
}