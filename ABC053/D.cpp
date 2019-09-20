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
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

const int MAX = 100000;
int cnt[MAX];
int n;

void init()
{
	memset(cnt, 0, sizeof cnt);

	cin >> n;
	REP(i, n)
	{
		int tmp;
		cin >> tmp;
		++cnt[tmp - 1];
	}
}

void declare()
{
	int ans = 0;
	REP(i, MAX) ans += cnt[i];
	cout << ans << endl;
}

int main()
{
	init();

	REP(a, MAX)
	{
		if (cnt[a] > 2)
		{
			if (cnt[a] & 1) cnt[a] = 1;
			else cnt[a] = 2;
		}
		
		if (cnt[a] == 2)
		{
			bool flag = true;
			int rem = -1;
			for (int b = a + 1; b < MAX; b++)
			{
				if (cnt[b] > 1)
				{
					flag = false;
					rem = b;

					if (!(cnt[b] & 1))
					{
						--cnt[b];
						--cnt[a];
						break;
					}
				}

			}

			if (flag)
			{
				int ans = 0;
				REP(i, MAX) ans += cnt[i];
				cout << ans - 2 << endl;
				return 0;
			}
			else if (cnt[a] == 2)
			{
				--cnt[a];
				--cnt[rem];
			}
		}
	}

	declare();
}
