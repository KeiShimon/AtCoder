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
	int n, ma{ -INTMAX }, mi{ INTMAX };
	int ma_i{ -1 }, mi_i{ -1 };
	vi a;
public:
	D()
	{
		cin >> n;
		a.resize(n);

		REP(i, n)
		{
			int tmp;
			cin >> tmp;
			if (chmax(ma, tmp))
				ma_i = i;
			if (chmin(mi, tmp))
				mi_i = i;
			a[i] = tmp;
		}
	}

	void solve()
	{
		vvi ans;
		int m{ 0 };

		if ((ma ^ mi) < 0)
		{
			if (-mi > ma)
			{
				// make all negative
				ma = -1;
				REP(i, n)
				{
					if (i != mi_i)
					{
						ans.emplace_back(vi{ mi_i + 1, i + 1 });
						++m;
					}
				}
			}
			else
			{
				// make all positive
				mi = 0;
				REP(i, n)
				{
					if (i != ma_i)
					{
						ans.emplace_back(vi{ ma_i + 1, i + 1 });
						++m;
					}
				}
			}
		}

		if (ma < 0)
		{
			for (int i{ n - 1 }; i >= 1; i--)
			{
				ans.emplace_back(vi{ i + 1 , i });
				++m;
			}
		}

		else
		{
			REP(i, n - 1)
			{
				ans.emplace_back(vi{ i + 1, i + 2 });
				++m;
			}
		}

		cout << m << endl;
		REP(i, m)
			cout << ans[i][0] << " " << ans[i][1] << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}