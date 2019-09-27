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

string s;
int n;
Vi rightRL, leftRL;
Vi ans;

void init()
{
	cin >> s; n = SZ(s);
	rightRL.resize(n, n);
	leftRL.resize(n, -1);
	ans.resize(n, 0);

	for(int i = n - 2; i >= 0; --i)
	{
		if (s[i] == 'R' && s[i + 1] == 'L')
			rightRL[i] = i;
		else
			rightRL[i] = rightRL[i + 1];
	}

	for (int i = 1; i <= n - 1; ++i)
	{
		if (s[i - 1] == 'R' && s[i] == 'L')
			leftRL[i] = i;
		else
			leftRL[i] = leftRL[i - 1];
	}
}


int main()
{
	init();

	REP(i, n)
	{
		if (s[i] == 'R')
		{
			if (1 & rightRL[i] - i)
				++ans[rightRL[i] + 1];
			else
				++ans[rightRL[i]];
		}

		else
		{
			if (1 & i - leftRL[i])
				++ans[leftRL[i] - 1];
			else
				++ans[leftRL[i]];
		}
	}

	REP(i, n)
		cout << ans[i] << " ";
	cout << endl;
}


//// done A-D in 41min on Sep 26 2019. ////
