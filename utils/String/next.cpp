#include "template.h"

/*
	It creates a lookup array that tells the index of the first character to the right (including the index).

	O ( |S| )

*/


//// MUST HAVE EXTERNAL VARIABLES ////
vvi nxt;
int n;
string s;


//// BODY ////

void init()
{
	nxt.resize(n + 1, vi(26, n));

	RREP(i, n)
	{
		REP(j, 26)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}

}