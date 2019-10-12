#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define PB push_back
#define MP make_pair

typedef int64_t ll;
typedef vector<ll> Vl;
typedef pair<ll, int> pli;
using G = vector<vector<pli>>;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const ll linf = 1LL << 60;
const ll INF = linf;

template <class Tdist>
void Dijkstra(int org, const G& g, vector<Tdist>& d);

int n;
G g;
Vl d;

void init()
{
	cin >> n;
	g.resize(n);

	REP(_i, n-1)
	{
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].PB(MP(c, b));
		g[b].PB(MP(c, a));
	}
}


int main()
{
	init();

	Dijkstra(0, g, d);

	REP(i, n)
	{
		cout << ((ll)1 & d[i]) << endl;
	}
}


template <class Tdist>
void Dijkstra(int org, const G& g, vector<Tdist>& d)
{
	using P = pair<Tdist, int>;

	vector<bool> done(n, false);
	d.assign(n, INF);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P((Tdist)0, org));

	while (!que.empty())
	{
		Tdist c = que.top().first;
		int v = que.top().second;
		que.pop();
		done[v] = true;

		if (c > d[v])
			continue;

		for (P p : g[v])
			if (!done[p.second] && chmin(d[p.second], c + p.first))
				que.push(P(d[p.second], p.second));
	}
}
