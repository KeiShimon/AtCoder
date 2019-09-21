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

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


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

int main()
{
	cin >> n >> k;
	CumSum2D<int> white(k, k), black(k, k);

	REP(_i, n)
	{
		int x, y; char c;
		cin >> x >> y >> c;

		x %= (2 * k);
		y %= (2 * k);
		int isBlack = c == 'B';

		if (x >= k) { x -= k; isBlack ^= 1; }
		if (y >= k) { y -= k; isBlack ^= 1; }

		if (isBlack)
			black.add(y, x, 1);
		else
			white.add(y, x, 1);
	}

	white.cumulate();
	black.cumulate();

	int ans = 0;

	REP(y, k)
		REP(x, k)
	{
		int tmp = 0;
		tmp += black.get(y, x, k, k) + black.get(0, 0, y, x);
		tmp += white.get(y, 0, k, x) + white.get(0, x, y, k);

		chmax(ans, max(tmp, n - tmp));
	}

	cout << ans << endl;
}
