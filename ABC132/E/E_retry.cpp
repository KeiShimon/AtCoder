#include <iostream>
#include <queue>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define PB push_back
#define MP make_pair

using namespace std;

typedef int64_t ll;
typedef pair<ll, int> pli;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const ll linf = 1LL << 60;
const ll INF = linf;


using G = vector<vector<int>>;
G g;
int n, m, start, goal;
vector<ll> d;

template <class Tdist>
void Dijkstra(int org, const G& g, vector<Tdist>& d);

void init()
{
	cin >> n >> m;
	n *= 3;
	g.resize(n);

	REP(_i, m)
	{
		int a, b;
		cin >> a >> b; --a; --b;
		a *= 3; b *= 3;

		g[a    ].PB(b + 1);
		g[a + 1].PB(b + 2);
		g[a + 2].PB(b);
	}

	cin >> start >> goal; --start; --goal;
	start *= 3; goal *= 3;
}

int main()
{
	init();
	Dijkstra(start, g, d);

	if (d[goal] == INF)
		cout << -1 << endl;
	else
		cout << d[goal] / 3 << endl;
}

template <class Tdist>
void Dijkstra(int org, const G& g, vector<Tdist>& d)
{
	using P = pair<Tdist, int>;

	vector<bool> done(n, false);
	d.assign(n, INF);
	d[org] = 0;

	priority_queue<P, vector<P>, greater<P>> que;
	que.push(MP((Tdist)0, org));

	while (!que.empty())
	{
		Tdist c = que.top().first;
		int v = que.top().second;
		que.pop();
		done[v] = true;

		for (auto u : g[v])
			if (!done[u] && chmin(d[u], c + 1))
				que.push(P(d[u], u));
	}
}