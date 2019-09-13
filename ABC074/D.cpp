#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
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

using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const int MOD = 1000000007;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void inline swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void inline swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


class D {
	int n;
	vvll d;
	vector<vector<bool>> done;

public:
	D()
	{
		cin >> n;
		d.resize(n, vi(n));
		done.resize(n, vector<bool>(n, 0));

		REP(i, n)
			done[i][i] = true;

		REP(i, n)
			REP(j, n)
			cin >> d[i][j];

	}

	bool warshall_froyd(ll & ans)
	{

		REP(k, n)
			REP(i, n)
		{
			bool flag = true;
			ll best = LLMAX;
			REP(j, n)
			{
				if (d[i][j] == d[i][k] + d[j][k])
					flag = false;
			}

			if (flag)
				ans += d[i][j];
		}

		return true;
	}

	void solve()
	{
		ll ans = 0;
		if (!warshall_froyd(ans))
		{
			cout << "-1" << endl;
			return;
		}

		cout << ans / 2 << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}