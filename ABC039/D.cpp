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

int h, w;
vector<vector<char>> test;
vector<string> res;
const int dx[]{0, 0, 1, -1, 1, 1, -1, -1};
const int dy[]{1, -1, 0, 0, -1, 1, -1, 1};

void init()
{
	cin >> h >> w;
	REP(i, h)
	{
		string s; cin >> s;
		res.emplace_back(s);
	}
	test.resize(h, vector<char>(w, '.'));
}

void print(vector<string>& vs) { REP(i, h) cout << vs[i] << endl; }
void print(vector<vector<char>>& vvc) { REP(i, h) { REP(j, w) cout << vvc[i][j]; cout << endl; } }
void print(vector<vector<bool>>& vvb) { REP(i, h) { REP(j, w) { if (vvb[i][j]) cout << '#'; else cout << '.'; }; cout << endl; } }

int main()
{
	init();

	vector<vector<bool>> black(h, vector<bool>(w, true));

	REP(i, h)
		REP(j, w)
	{
		if (res[i][j] == '.')
		{
			black[i][j] = false;
			REP(d, 8)
			{
				if (i + dy[d] >= 0 && i + dy[d] < h && j + dx[d] >= 0 && j + dx[d] < w)
					black[i + dy[d]][j + dx[d]] = false;
			}
		}
	}

	REP(i, h)
		REP(j, w)
		if (black[i][j])
		{
			test[i][j] = '#';
			REP(d, 8)
			{
				if (i + dy[d] >= 0 && i + dy[d] < h && j + dx[d] >= 0 && j + dx[d] < w)
					test[i + dy[d]][j + dx[d]] = '#';
			}
		}

	REP(i, h)
		REP(j, w)
		if (test[i][j] != res[i][j])
		{
			cout << "impossible" << endl;
			return 0;
		}

	cout << "possible" << endl;
	print(black);
}
