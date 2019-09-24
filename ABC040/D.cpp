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


int n, m, q;
vi parent, ans;
vector<tupiii> bridge, query;

int root(int);
bool unite(int, int);

void init()
{
	cin >> n >> m;
	parent.resize(n, -1);
	bridge.reserve(m);

	REP(_i, m)
	{
		int a, b, y; cin >> a >> b >> y; --a; --b;
		bridge.emplace_back(tupiii(y, a, b));
	}

	cin >> q;
	query.reserve(q);
	ans.resize(q);
	REP(i, q)
	{
		int v, w; cin >> v >> w; --v;
		query.emplace_back(tupiii(w, v, i));
	}

	sort(ALL(query));
	sort(ALL(bridge));

}


int main()
{
	init();

	int brg = m - 1;
	RREP(i, q)
	{
		int y = get<0>(query[i]);
		int pos = get<1>(query[i]);

		while ( brg >= 0 && get<0>(bridge[brg]) > y)
		{
			unite(get<1>(bridge[brg]), get<2>(bridge[brg]));
			--brg;
		}

		ans[get<2>(query[i])] = -parent[root(pos)];
	}

	REP(i, q)
		cout << ans[i] << endl;
}


int root(int a)
{
	if (parent[a] < 0)
		return a;
	return parent[a] = root(parent[a]);
}


bool unite(int a, int b)
{
	int root_a = root(a);
	int root_b = root(b);

	if (root_a == root_b)
		return false;

	int size_a = -parent[root_a];
	int size_b = -parent[root_b];

	if (size_a < size_b)
	{
		swap(a, b); swap(size_a, size_b); swap(root_a, root_b);
	}

	parent[root_a] += -size_b;
	parent[root_b] = root_a;

	return true;
}