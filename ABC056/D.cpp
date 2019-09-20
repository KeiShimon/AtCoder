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
vll va;
vector<bool> nec;

void init()
{
	cin >> n >> k;
	nec.resize(n, false);
	va.resize(n);
	REP(i, n) cin >> va[i];

	sort(ALL(va));
}

void declare()
{
	int ans = 0;
	REP(i, n)
		if (!nec[i]) ++ans;
	cout << ans << endl;
}

int main()
{
	init();

	REP(chk, n)
	{
		if (va[chk] >= k || nec[chk])
		{
			nec[chk] = true;
			continue;
		}

		ll s = va[chk];
		int left = chk + 1, right = chk + 2;
		if (left < n)
			s += va[left];

		while (left < n)
		{
			while (s < k && right < n)
			{
				s += va[right++];
			}
//			cout << "chkID, chkval = " << chk << ", " << va[chk] << " [ " << left << ", " << right << " )" << ", s = " << s << endl;

			if (s >= k)
			{
				if (s - va[chk] < k)
					nec[chk] = true;
				for (int i = left; i < right; i++)
					if (s - va[i] < k)
						nec[i] = true;
			}

			s -= va[left++];
		}
	}

	//REP(i, n)
	//	cout << va[i] << " : " << nec[i] << endl;
	//cout << endl;

	declare();
}
