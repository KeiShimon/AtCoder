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

int n, k;
Vi va;
Vi divisors;

void init()
{
	cin >> n >> k;
	va.resize(n);
	REP(i, n) cin >> va[i];

	int all = accumulate(ALL(va), 0);
	int lim = (int)ceil(sqrt(all));
	REP1C(d, lim)
		if (!(all % d))
		{
			divisors.PB(d);
			divisors.PB(all / d);
		}
	sort(ALL(divisors), greater<>());
}


int main()
{
	init();

	for (int d : divisors)
	{
		Vi tmp(n);
		int s = 0;
		REP(i, n)
		{
			tmp[i] = va[i] % d;
			s += tmp[i];
		}

		if (!s)
		{
			cout << d << endl;
			return 0;
		}

		sort(ALL(tmp), greater<>());
		int piles = s / d;
		int a = 0;
		for (int i = 0; i < piles && i < SZ(tmp); ++i)
		{
			a += d - tmp[i];
		}
		if (a <= k)
		{
			cout << d << endl;
			return 0;
		}
	}
}
