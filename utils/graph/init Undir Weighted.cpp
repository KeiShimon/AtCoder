#include "template.h"


//// MUST INCLUDE ////


//// MUST HAVE EXTERNAL VARIABLES ////

using G = vector<vector<pli>>;
G g;

int n, m;


//// BODY ////

void init()
{
	cin >> n >> m;

	g.resize(n);

	REP(i, m)
	{
		int a, b; ll c; cin >> a >> b >> c; --a; --b;

		g[a].emplace_back(MP(c, b));
		g[b].emplace_back(MP(c, a));
	}
}