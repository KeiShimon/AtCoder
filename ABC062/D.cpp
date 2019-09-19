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

priority_queue<int, vi, greater<int>> ql;
priority_queue<int, vi> qr;
vvll memo;
vll a;
int n;

void init()
{
	cin >> n;
	a.resize(3 * n);
	REP(i, 3 * n)
		cin >> a[i];

	memo.resize(2, vll(3 * n, 0));
}

int main()
{
	init();

	int i = 0;
	ll curl = 0;

	for (; i < n; ++i)
	{
		ql.push(a[i]);
		curl += a[i];
	}
	
	for (; i < 2 * n; i++)
	{
		memo[0][i] = curl;

		if (a[i] > ql.top())
		{
			curl += a[i] - ql.top();
			ql.pop();
			ql.push(a[i]);
		}
	}
	memo[0][i] = curl;

	ll curr = 0;
	i = 3 * n - 1;
	for (; i >= 2 * n; --i)
	{
		qr.push(a[i]);
		curr += a[i];
	}
	for (; i >= n; --i)
	{
		memo[1][i + 1] = curr;

		if (a[i] < qr.top())
		{
			curr += a[i] - qr.top();
			qr.pop();
			qr.push(a[i]);
		}

		//cout << curr << endl;
	}
	memo[1][i + 1] = curr;


	//REP(i, 3 * n)
	//	cout << memo[0][i] << " ";
	//cout << endl;
	//REP(i, 3 * n)
	//	cout << memo[1][i] << " ";
	//cout << endl;

	ll ans = -LLMAX;

	for (i = n; i <= 2 * n; i++)
	{
		chmax(ans, memo[0][i] - memo[1][i]);
	}

	cout << ans << endl;

}
