#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class C {
	int a, b, ab;
	int needa, needb;
public:
	C()
	{
		cin >> a >> b >> ab >> needa >> needb;

		if (needa > needb)
		{
			needa ^= needb; needb ^= needa; needa ^= needb;
			a ^= b; b ^= a; a ^= b;
		}
	}
	void solve()
	{
		ll ans{ LLMAX };
		int tmpa, tmpb;
		ll tmpcost;

		// make all a with ab
		// make all b with ab
		tmpa = needa; tmpb = needb;
		tmpcost = 2LL * ab * tmpa;
		tmpb -= tmpa;
		if (tmpb)
			tmpcost += 2LL * ab * tmpb;
		chmin(ans, tmpcost);

		// make all a with ab
		// make remaining b with b
		tmpa = needa; tmpb = needb;
		tmpcost = 2LL * ab * tmpa;
		tmpb -= tmpa;
		if (tmpb > 0)
			tmpcost += (ll)b * tmpb;
		chmin(ans, tmpcost);

		// make all a with a
		// make all b with b
		tmpa = needa; tmpb = needb;
		tmpcost = (ll)a * needa;
		tmpcost += (ll)b * needb;
		chmin(ans, tmpcost);

		// make all a with a
		// make all b with ab
		tmpa = needa; tmpb = needb;
		tmpcost = (ll)a * needa;
		tmpcost += 2LL * ab * needb;
		chmin(ans, tmpcost);

		cout << ans << endl;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}