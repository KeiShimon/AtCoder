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


void print(vvi v)
{
	REP(i, SZ(v))
	{
		REP(j, SZ(v[i]))
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

class D {
	int n, k;
	vvll loc;
	vvi memo;

public:
	D()
	{
		cin >> n >> k;
		loc.resize(n, vll(2));
		memo.resize(n, vi(8, 0));

		REP(i, n)
		{
			cin >> loc[i][0];
			cin >> loc[i][1];
		}
	}

	void solve()
	{

		REP(i, n)
			REP(j, n)
		{
			if (i == j)
				continue;

			if (loc[j][0] > loc[i][0])
			{
				++memo[i][0];
				if (loc[j][1] > loc[i][1])
				{
					++memo[i][6];
					++memo[i][7];
				}
				else
				{
					++memo[i][2];
					++memo[i][1];
				}
			}

			else
			{
				++memo[i][4];
				if (loc[j][1] > loc[i][1])
				{
					++memo[i][6];
					++memo[i][5];
				}
				else
				{
					++memo[i][2];
					++memo[i][3];
				}
			}
		}

		ll ans{ LLMAX };

		REP(i, n)
			REP(j, n)
		{
			if (i == j)
				continue;

			int cnt = n;

			if (loc[j][0] > loc[i][0])
			{
				cnt -= memo[j][0];
				cnt -= memo[i][4];
				if (loc[j][1] > loc[i][1])
				{
					cnt -= memo[j][6];
					cnt -= memo[i][2];
					cnt += memo[i][3];
					cnt += memo[j][7];
				}
				else
				{
					cnt -= memo[i][6];
					cnt -= memo[j][2];
					cnt += memo[j][1];
					cnt += memo[i][5];
				}
			}

			else
			{
				cnt -= memo[i][0];
				cnt -= memo[j][4];
				if (loc[j][1] > loc[i][1])
				{
					cnt -= memo[j][6];
					cnt -= memo[i][2];
					cnt += memo[i][1];
					cnt += memo[j][5];
				}
				else
				{
					cnt -= memo[i][6];
					cnt -= memo[j][2];
					cnt += memo[j][3];
					cnt += memo[i][7];
				}
			}

			if (k <= cnt)
			{
				ll h = abs(loc[i][1] - loc[j][1]);
				ll w = abs(loc[i][0] - loc[j][0]);
				chmin(ans, h * w);
			}
		}

		cout << ans << endl;

	}
};

int main()
{
	D solution;
	solution.solve();

	return 0;
}