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


#include <unordered_set>

int n, m;
int c[10]{ 0,2,5,5,4,5,6,3,7,6 };
bool d[10];
vvi dp;
vi un;
unordered_set<int> s;

void init()
{
	memset(d, false, sizeof d);
	cin >> n >> m;
	dp.resize(n + 1, vi(8, 0));
	REP(i, m)
	{
		int a;
		cin >> a;
		d[a] = true;
		s.insert(c[a]);
	}

	for (auto it = s.begin(); it != s.end(); it++)
		un.PB(*it);

}

int main()
{
	init();

	REP(i, n)
	{
		for (int cst : un)
		{
			if (i + cst <= n)
			{
				if (chmax(dp[i + cst][0], dp[i][0] + 1))
				{
					for (int tmp : un)
						dp[i + cst][tmp] = dp[i][tmp];
					++dp[i + cst][cst];
				}
			}
		}
	}
	
	ostringstream oss;

	for (int x = 9; x >= 1; x--)
	{
		if (d[x])
		{
			while (dp[n][c[x]])
			{
				oss << x;
				--dp[n][c[x]];
			}
		}
	}

	cout << oss.str() << endl;
}