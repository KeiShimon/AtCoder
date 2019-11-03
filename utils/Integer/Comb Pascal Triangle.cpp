#include "template.h"


ll C[51][51]; // C[n][k] -> nCk

void comb_table(int N)
{
	REPC(i, N)
		REPC(j, i)
	{
		if (j == 0 or j == i)
			C[i][j] = 1LL;
		else
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
	}
}