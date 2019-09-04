#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

vector<int64_t> factMemo{ 1, 1 };
int curMax{ 1 };


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