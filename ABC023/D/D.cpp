#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++)

typedef int64_t ll;
typedef vector<int> Vi;
typedef vector<ll> Vl;

const ll linf = 1LL << 60;

int n;
ll vh[100000], vs[100000];

bool check(ll x)
{
	Vi cum(n + 1, 0);

	REP(i, n)
	{
		if (x < vh[i])
			return false;

		int timeLimit = min((ll)n, (x - vh[i]) / vs[i] + 1);
		cum[timeLimit]++;
	}

	REP1C(i, n)
	{
		cum[i] += cum[i - 1];
		if (cum[i] > i)
			return false;
	}

	return true;
}

int main()
{
	cin >> n;
	REP(i, n) cin >> vh[i] >> vs[i];

	ll ng = 0, ok = linf;
	while (abs(ng - ok) > 1)
	{
		auto mid = (ng + ok) / 2;

		if (check(mid))
			ok = mid;
		else
			ng = mid;
	}

	cout << ok << endl;
}
