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

#include <bitset>

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


class C {
	string s;
	int a[4];
public:
	C()
	{
		cin >> s;
		REP(i, 4)
			a[i] = s[i] - '0';
	}
	void solve()
	{
		int mask{ 0 };
		int tmp;
		for (; mask <= 0b111; mask++)
		{
			tmp = a[0];
			for (int bit{ 0 }; bit < 3; bit++)
			{
				if (mask & (1 << bit))
					tmp += a[bit + 1];
				else
					tmp -= a[bit + 1];
			}

			if (tmp == 7)
				break;
		}

		cout << a[0];

		REP(i, 3)
		{
			if (mask & (1 << (i)))
				cout << "+" << a[i + 1];
			else
				cout << "-" << a[i + 1];
		}
		cout << "=7" << endl;

	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}