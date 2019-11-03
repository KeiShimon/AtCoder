#include "template.h"

vector<vector<double>> combProb;
void calcCombProbability(int n)
{
	combProb.resize(n + 1);
	combProb[0].resize(2, 0);
	combProb[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		combProb[i].resize(i + 2, 0);
		combProb[i][0] = combProb[i - 1][0] / 2;
		for (int j = 1; j <= i; ++j)
			combProb[i][j] = (combProb[i - 1][j - 1] + combProb[i - 1][j]) / 2;
	}
}