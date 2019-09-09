#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
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
typedef pair<int, int> pii;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

class D {
	int rows, cols;
	int d, q;
	vector<pii> pos;
	vector<ll> memo;
public:
	D()
	{
		cin >> rows >> cols;
		cin >> d;

		pos.resize(rows * cols + 1);
		memo.resize(rows * cols + 1);

		int v;
		REP(y, rows)
			REP(x, cols)
		{
			cin >> v;
			pos[v] = MP(y, x);
		}

		cin >> q;

	}

	inline ll diff(const int& s, const int& g)
	{
		return (ll)abs(pos[s].first - pos[g].first) + abs(pos[s].second - pos[g].second);
	}

	void memoize()
	{

		for (int s{ 1 }; s <= d; s++)
		{
			memo[s] = 0;

			for (int g{ s + d }; g <= rows * cols; g += d)
				memo[g] = memo[g - d] + diff(g, g - d);

		}

	}

	void solve()
	{
		memoize();

		int s, g;
		REP(_q, q)
		{
			ll ans{ 0 };
			cin >> s >> g;

			ans += memo[g] - memo[s];

			cout << ans << endl;
		}

	}

	void debug()
	{
		REPC(i, rows * cols)
		{
			cout << i << " is at (" << pos[i].first << ", " << pos[i].second << ")." << endl;
		}

		cout << endl << endl;

		REP1C(i, rows * cols)
		{
			cout << memo[i] << " ";
			if (!(i % d))
				cout << endl;
		}

		cout << endl << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}