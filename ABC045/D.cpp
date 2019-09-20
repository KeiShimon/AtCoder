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

#include <map>
map<pii, int> memo;
int h, w, n;

const int dx[9]{ -1, -1, -1, 0, 0, 0, 1 ,1, 1 };
const int dy[9]{ 0, 1, -1, 0, 1, -1, 0, 1, -1 };

int main()
{
	cin >> h >> w >> n;

	REP(_i, n)
	{
		int x, y;
		cin >> y >> x;
		y--; x--;
//		cout << "from [ " << x << " , " << y << " ]" << endl;
		REP(i, 9)
		{
			int cx = x + dx[i];
			int cy = y + dy[i];

//			cout << "  checking [ " << cx << " , " << cy << " ]" << endl;

			if (cx - 1 >= 0 && cx + 1 < w && cy - 1 >= 0 && cy + 1 < h)
			{
				memo[pii(cx, cy)]++;
			}
		}
	}

	vll ans(10, 0);
	ans[0] = ((ll)h - 2) * ((ll)w - 2);

	for (auto it = memo.begin(); it != memo.end(); it++)
	{
//		cout << "[ " << it->first.first << ", " << it->first.second << " ] : " << it->second << endl;
		ans[it->second]++;
		ans[0] -= 1;
	}

	REP(i, 10)
		cout << ans[i] << endl;
}
