#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
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
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<char> Vc;
typedef vector<string> Vs;
typedef vector<bool> Vb;
typedef vector<vector<int>> VVi;
typedef vector<vector<ll>> VVl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> P;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }
inline void YES() { cout << "YES" << endl; }
inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; }
inline void No() { cout << "No" << endl; }

const int inf = 1 << 30;
const ll linf = 1LL << 60;
const int MOD = 1000000007;

#include <limits.h>

template <class T>
struct CumSum2D {
private:
	const int h, w;
	vector<vector<T>> data;
public:
	CumSum2D(int h, int w) : data(h + 1, vector<T>(w + 1, (T)0)), h{ h + 1 }, w{ w + 1 } {}
	void add(int i, int j, T val) { if ((i + 1) < h && (j + 1) < w) data[i + 1][j + 1] += val; }
	void cumulate() { REP1O(i, h) REP1O(j, w) data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1]; }

	// [s, g) , s : btm-left, g : top-right
	T get(int si, int sj, int gi, int gj) { return data[gi][gj] + data[si][sj] - data[gi][sj] - data[si][gj]; }
};

int n, k;
Vi vx, vy;
VVi pts;

void init()
{
	cin >> n >> k;
	vx.resize(n); vy.resize(n);
	pts.resize(n, Vi(2));
	REP(i, n) 
	{
		cin >> vx[i] >> vy[i];
		pts[i][0] = vx[i];
		pts[i][1] = vy[i];
	}

	sort(ALL(vx)); sort(ALL(vy));
}

int main()
{
	init();

	ll ans = LLONG_MAX;

	CumSum2D<int> cum(n, n);
	REP(i, n)
	{
		int i_x = lower_bound(ALL(vx), pts[i][0]) - vx.begin();
		int i_y = lower_bound(ALL(vy), pts[i][1]) - vy.begin();
		cum.add(i_x, i_y, 1);
	}
	cum.cumulate();

	REP(l, n - 1)
		for (int r = l + 1; r < n; ++r)
		REP(d, n - 1)
			for (int u = d + 1; u < n; ++u)
			{
				int n = cum.get(l, d, r + 1, u + 1);
				if (n >= k)
					chmin(ans, (ll)(vx[r] - vx[l]) * (ll)(vy[u] - vy[d]));
			}

	cout << ans << endl;
}
