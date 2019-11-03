#include <algorithm>
#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

int va[101];

int main()
{
	int N; cin >> N;
	REP(i, N) cin >> va[i];

	sort(va, va + 100, greater<>());

	int ma = va[0];
	int i = 0;
	while (va[i] == ma)
		++i;

	cout << va[i] << endl;
}
