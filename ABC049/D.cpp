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

#include <map>

vector<int> road, train;
int root(int, vi&);
bool unite(int, int, vi&);
int n, k, l;
map<pii, int> cnt;

void init()
{
	cin >> n >> k >> l;
	road.resize(n, -1);
	train.resize(n, -1);
}

int main()
{
	init();

	REP(_i, k)
	{
		int p, q;
		cin >> p >> q; --p; --q;
		unite(p, q, road);
	}
	REP(_i, l)
	{
		int p, q;
		cin >> p >> q; --p; --q;
		unite(p, q, train);
	}

	REP(i, n)
	{
		cnt[pii(root(i, road), root(i, train))]++;
	}

	REP(i, n)
	{
		cout << cnt[pii(root(i, road), root(i, train))] << " ";
	}
	cout << endl;

}


int root(int a, vi& v)
{
	if (v[a] < 0)
		return a;
	return v[a] = root(v[a], v);
}


bool unite(int a, int b, vi& v)
{
	int root_a = root(a, v);
	int root_b = root(b, v);

	if (root_a == root_b)
		return false;

	int size_a = -v[root_a];
	int size_b = -v[root_b];

	if (size_a < size_b)
	{
		swap(a, b); swap(size_a, size_b); swap(root_a, root_b);
	}

	v[root_a] += -size_b;
	v[root_b] = root_a;

	return true;
}
