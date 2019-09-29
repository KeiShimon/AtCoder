#include "template.h"


//// MUST HAVE EXTERNAL VARIABLES ////

using G = vector<vector<int>>;

G g;
int n, m;


//// BODY ////

void init()
{
	cin >> n >> m;
	g.resize(n);

	REP(i, m)
	{
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}