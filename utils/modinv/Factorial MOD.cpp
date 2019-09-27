#include "template.h"


//// MUST HAVE EXTERNAL VARIABLES ////

void initFactTable(int);
int64_t factorial(int n);

vector<int64_t> factMemo{ 1, 1 };
int curMax{ 1 };


//// BODY ////

void initFactTable(int n)
{
	factMemo.resize(n + 1);
	while (curMax < n)
	{
		curMax++;
		factMemo[curMax] = factMemo[curMax - 1] * curMax % MOD;
	}
}

int64_t factorial(int n)
{
	if (curMax < n)
		initFactTable(n);

	return factMemo[n];
}