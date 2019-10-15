#include "template.h"

typedef pair<ll, int> P;
using G = vector<vector<P> >;

void init();

G g;
int n, m;

void init()
{
	cin >> n >> m;
	g.resize(n);

	REP(_i, m)
	{
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;

		g[a].push_back(P(c, b));
		g[b].push_back(P(c, a));
	}
}