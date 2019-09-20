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

int n, k;
vi vv;

void init()
{
	cin >> n >> k;
	vv.resize(n);
	REP(i, n) cin >> vv[i];
}

int main()
{
	init();

	vi tmp1;
	int ans = 0;

	for (int left = 0; left <= k && left <= n; left++)
	{
		if (left)
			tmp1.PB(vv[left - 1]);

		for (int right = 0; right <= (k - left) && right + left <= n; right++)
		{
			vi tmp2(tmp1);
			for (int i = n - 1; i >= (n - right); --i)
				tmp2.PB(vv[i]);

			//cout << "left = " << left << ", right = " << right << " vec = [ ";
			//REP(i, SZ(tmp2))
			//	cout << tmp2[i] << " ";
			//cout << " ]" << endl;

			int s = accumulate(ALL(tmp2), 0);
			sort(ALL(tmp2));

			int rm = 0;
			while (rm < (k - left - right) && rm < (left + right))
			{
				if (tmp2[rm] < 0)
					s -= tmp2[rm++];
				else
					break;
			}
			chmax(ans, s);
		}
	}

	cout << ans << endl;

}
