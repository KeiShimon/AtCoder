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

#include <set>

typedef tuple<int, int, int> tup;

int n, q;

auto sortBegin = [](const tup& left, const tup& right) { return get<0>(left) > get<0>(right); };
auto sortEnd = [](const tup& left, const tup& right) { return get<1>(left) > get<1>(right); };

multiset<int> stop;
priority_queue<tup, vector<tup>, decltype(sortBegin)> pending(sortBegin);
priority_queue<tup, vector<tup>, decltype(sortEnd)> active(sortEnd);

vector<pii> query;
Vi ans;

void init()
{
	cin >> n >> q;
	REP(_i, n)
	{
		int s, t, x;
		cin >> s >> t >> x;
		s = max(0, s - x);
		t = max(0, t - x);

		pending.push(tup(s, t, x));
	}
	query.reserve(q);
	ans.resize(q);
	REP(i, q)
	{
		int t; cin >> t;
		query.emplace_back(pii(t, i));
	}
	sort(ALL(query));
}

int main()
{
	init();

	REP(i, q)
	{
		int t = query[i].first;

		while (!pending.empty() && get<0>(pending.top()) <= t)
		{
			stop.insert(get<2>(pending.top()));
			active.push(pending.top());
			pending.pop();
		}

		while (!active.empty() && get<1>(active.top()) <= t)
		{
			stop.erase(stop.find(get<2>(active.top())));
			active.pop();
		}

		if (!stop.empty())
			ans[query[i].second] = *(stop.begin());
		else
			ans[query[i].second] = -1;
	}

	REP(i, q)
		cout << ans[i] << endl;
}
