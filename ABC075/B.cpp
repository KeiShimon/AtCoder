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

class B {
	int h, w;
	vector<string> f;
public:
	B()
	{
		cin >> h >> w;
		f.resize(h);
		REP(i, h)
			cin >> f[i];
	}
	void solve()
	{

		REP(y, h)
		{
			REP(x, w)
			{
				if (f[y][x] == '.')
				{
					char cnt = '0';

					for (int dx = -1; dx <= 1; dx++)
						for (int dy = -1; dy <= 1; dy++)
						{
							if (y + dy >= 0 && y + dy < h && x + dx < w && x + dx >= 0)
								if (f[y + dy][x + dx] == '#')
									cnt++;
						}

					f[y][x] = cnt;
				}

			}
		}

		REP(y, h)
			cout << f[y] << endl;

	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}