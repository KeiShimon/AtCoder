#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> Vi;

int v[5];
Vi ans;

int main()
{
	REP(i, 5)
		cin >> v[i];

	REP(i, 3)
		for (int j = i + 1; j < 4; ++j)
			for (int k = j + 1; k < 5; ++k)
			{
				int tmp = v[i] + v[j] + v[k];
				ans.PB(tmp);
			}

	sort(ALL(ans));

	cout << ans[7] << endl;
}
