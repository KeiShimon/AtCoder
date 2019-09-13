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


class C {
	int a, b;
	int c, d;
	int ma;
	int cap;
public:
	C()
	{
		cin >> a >> b >> c >> d >> ma >> cap;
		a *= 100;
		b *= 100;
	}
	void solve()
	{

		double maxConc = 0;
		int maxW = 0;
		int maxS = 0;

		for (int addA = 0; addA <= cap / a; addA++)
		{
			int wat = addA * a;

			for (int addB = 0; addB * b + wat <= cap; addB++)
			{
				wat += addB * b;

				for (int addC = 0; addC * c + wat <= cap && addC * c <= (wat / 100 * ma); addC++)
				{
					int sug = addC * c;

					for (int addD = 0; addD * d + wat + sug <= cap && sug + addD * d <= (wat / 100 * ma); addD++)
					{
						sug += addD * d;

						double conc = (double)sug / ((double)wat + sug);
						if (chmax(maxConc, conc))
						{
							maxW = wat;
							maxS = sug;
						}

						sug -= addD * d;
					
					}

					sug -= addC * c;
				}

				wat -= addB * b;
			}

		}

		if (maxW)
			cout << maxW + maxS << " " << maxS << endl;
		else
			cout << a << " " << 0 << endl;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}