#include "template.h"


//// MUST INCLUDE ////



//// MUST HAVE EXTERNAL VARIABLES ////
vector<vector<int>> g;
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