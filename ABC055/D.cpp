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

string s;
int n;
vector<char>ans;

void print()
{
	REP(i, n)
		cout << ans[i];
	cout << endl;
}

bool check(char f, char r)
{
	ans.clear();
	ans.resize(n);

	ans[0] = f; ans[1] = r;

	for (int i = 1; i < n - 1; i++)
	{
		if (s[i] == 'o')
		{
			if (ans[i] == 'S')
				ans[i + 1] = ans[i - 1];
			else
			{
				if (ans[i - 1] == 'W') ans[i + 1] = 'S';
				else ans[i + 1] = 'W';
			}
		}
		else // if (s[i] == 'x')
		{
			if (ans[i] == 'W') ans[i + 1] = ans[i - 1];
			else
			{
				if (ans[i - 1] == 'W') ans[i + 1] = 'S';
				else ans[i + 1] = 'W';
			}
		}
	}


	if (ans[n - 1] == 'S')
	{
		if (s[n - 1] == 'o')
		{
			if (ans[0] != ans[n - 2]) return false;
		}
		else
			if (ans[0] == ans[n - 2]) return false;
	}
	else // if (ans[n - 1] == 'W')
	{
		if (s[n - 1] == 'o') //Wo
		{
			if (ans[0] == ans[n - 2]) return false;
		}
		else // Wx
			if (ans[0] != ans[n - 2]) return false;
	}

	if (ans[0] == 'S')
	{
		if (s[0] == 'o')
		{
			if (ans[1] != ans[n - 1]) return false;
		}
		else
			if (ans[1] == ans[n - 1]) return false;
	}
	else
	{
		if (s[0] == 'o')
		{
			if (ans[1] == ans[n - 1]) return false;
		}
		else
			if (ans[1] != ans[n - 1]) return false;
	}

	return true;
}

int main()
{
	cin >> n >> s;
	ans.resize(n);

	if (check('S', 'W')) { print(); return 0; }
	if (check('S', 'S')) { print(); return 0; }
	if (check('W', 'W')) { print(); return 0; }
	if (check('W', 'S')) { print(); return 0; }

	cout << -1 << endl;
}
