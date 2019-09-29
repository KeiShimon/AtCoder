#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
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
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef double dbl;
typedef vector<bool> Vb;
typedef vector<char> Vc;
typedef vector<double> Vd;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<string> Vs;
typedef vector<vector<int>> VVi;
typedef vector<vector<ll>> VVl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }
inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

const int inf = 1 << 30;
const ll linf = 1LL << 60;
const int MOD = 1000000007;

string s, t;
ll ns, nt;
bool exist[26];
VVi nxt;

void init()
{
	cin >> s >> t;
	ns = SZ(s);
	nt = SZ(t);
	nxt.resize(ns + 1, Vi(26, ns));

	RREP(i, ns)
	{
		exist[s[i] - 'a'] = true;
		REP(j, 26) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}
}


int main()
{
	init();

	ll ans = 1;
	int i = 0;
	for (char c : t)
	{
		int ci = c - 'a';

		if (!exist[ci])
		{
			cout << -1 << endl;
			return 0;
		}

		if (nxt[i][ci] != ns)
		{
			ans += ((ll)nxt[i][ci] - i);
			i = nxt[i][ci];
		}
		else
		{
			ans += ns - i;
			ans += (ll)nxt[0][ci];
			i = nxt[0][ci];
		}
	}

	cout << ans << endl;
}
