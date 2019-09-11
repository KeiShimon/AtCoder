#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
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

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


class D {
	int h, w;
	static const int v{ 10 };
	int H, W, C[10][10];

public:
	D()
	{
		cin >> H >> W;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> C[i][j];
			}
		}
	}

	void init()
	{
		REP(k, v)
			REP(i, v)
			REP(j, v)
			C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
	}
	void solve()
	{
		init();

		long long ret = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int x;
				cin >> x;
				if (~x) ret += C[x][1];
			}
		}

		cout << ret << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}