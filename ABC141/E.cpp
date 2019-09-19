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

int n;
string s;
vvi nxt;

void init()
{
	cin >> n >> s;

	nxt.resize(n + 1, vi(26, n));

	RREP(i, n)
	{
		REP(j, 26)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i;
	}

}

void print()
{
	REP(i, SZ(nxt))
	{
		REP(j, 26)
			cout << nxt[i][j] << " ";
		cout << endl;
	}

}

int main()
{
	init();

	int ans = 0;

	REP(c, 26)
	{
		int left = nxt[0][c];
		int right = n;

		if (left < n)
			right = nxt[left + 1][c];

		while (left < n && right < n)
		{
			int len;
			if (ans)
				len = ans;
			else
				len = 1;

			if ((right + len - 1 < n) && ((left + len - 1) < right))
			{
				bool flag = true;
				REP(i, len)
				{
					if (s[left + i] != s[right + i])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					while ((s[left + len - 1] == s[right + len - 1]) && (right + len - 1 < n) && ((left + len - 1) < right))
					{
						chmax(ans, len);
						++len;
					}
				}
			}

			right = nxt[right + 1][c];

			if (right == n || right + len - 1 >= n)
			{
				left = nxt[left + 1][c];

				if (left < n)
					right = nxt[left + 1][c];
				else
					right = n;
			}
		}
	}

	cout << ans << endl;
}