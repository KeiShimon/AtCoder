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

typedef pair<ll, int> P;
vector<vector<pair<ll, int>>> g;
vector<tupiii> loc;
int n;


void init()
{
	cin >> n;
	g.resize(n);
	loc.resize(n);

	REP(i, n)
	{
		int a, b; cin >> a >> b;
		loc[i] = tupiii(a, b, i);
	}

	sort(ALL(loc), [](const tupiii& left, const tupiii& right) { return get<0>(left) < get<0>(right); });

	REP(i, n - 1)
	{
		g[get<2>(loc[i])].emplace_back(MP(abs(get<0>(loc[i + 1]) - get<0>(loc[i])), get<2>(loc[i + 1])));
		g[get<2>(loc[i + 1])].emplace_back(MP(abs(get<0>(loc[i + 1]) - get<0>(loc[i])), get<2>(loc[i])));
	}

	sort(ALL(loc), [](const tupiii& left, const tupiii& right) { return get<1>(left) < get<1>(right); });

	REP(i, n - 1)
	{
		g[get<2>(loc[i])].emplace_back(MP(abs(get<1>(loc[i + 1]) - get<1>(loc[i])), get<2>(loc[i + 1])));
		g[get<2>(loc[i + 1])].emplace_back(MP(abs(get<1>(loc[i + 1]) - get<1>(loc[i])), get<2>(loc[i])));
	}

}

ll Prim()
{
	vector<bool> done(n, false);
	ll tot = 0;

	REP(i, n)
	{
		if (!done[i])
		{
			priority_queue<P, vector<P>, greater<P>> que;
			que.push(MP(0LL, i));

			while (!que.empty())
			{
				int v = que.top().second;
				ll c = que.top().first;
				que.pop();

				if (!done[v])
				{
					done[v] = true;
					tot += c;

					for (P adj : g[v])
						que.push(adj);
				}
			}
		}
	}

	return tot;
}


int main()
{
	init();

	ll ans = Prim();

	cout << ans << endl;

}
