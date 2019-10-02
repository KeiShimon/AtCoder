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



int main()
{
	int h, w, a, b;
	cin >> h >> w >> a >> b;

	if (h == 1 || w == 1)
	{
		if (h == 1 && b) { cout << "No" << endl; return 0; }
		if (w == 1 && a) { cout << "No" << endl; return 0; }

		if (h == 1)
		{
			REP(_i, a) cout << 1;
			REP(_i, (w - a)) cout << 0;
			cout << endl;
		}
		else
		{
			REP(_i, b) cout << 1 << endl;
			REP(_i, (h - b)) cout << 0 << endl;
		}

		return 0;
	}

	vi cnt1_c(w, 0), cnt1_r(h, 0);
	vi cnt0_c(w, h), cnt0_r(h, w);
	vvi ans(h, vi(w, 0));

	REP(i, h)
		REP(j, w)
	{
		if (cnt0_c[j] > b && cnt0_r[i] > a)
		{
			if (cnt1_r[i] < a || cnt1_c[j] < b)
				if (!(cnt1_r[i] < cnt0_r[i] && cnt1_r[i] == a))
					if (!(cnt1_c[j] < cnt0_c[j] && cnt1_c[j] == b))
						{
							ans[i][j] = 1;
							cnt1_c[j]++; cnt1_r[i]++;
							cnt0_c[j]--; cnt0_r[i]--;
						}
		}
	}

	//REP(i, h)
	//{
	//	REP(j, w)
	//		cout << ans[i][j];
	//	cout << endl;
	//}

	REP(i, h)
		if (min(cnt1_r[i], cnt0_r[i]) != a)
		{
			cout << "No" << endl; return 0;
		}
	REP(j, w)
		if (min(cnt1_c[j], cnt0_c[j]) != b)
		{
			cout << "No" << endl; return 0;
		}

	REP(i, h)
	{
		REP(j, w)
			cout << ans[i][j];
		cout << endl;
	}
}
