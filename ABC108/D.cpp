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
	int L;
	int N{ 0 };
	int n_edges{ 0 };
	int gaps;
	vector<tupiii> added;
public:
	D()
	{
		cin >> L;

		int pow{ 1 };
		while (pow <= L) pow *= 2, ++N;

		gaps = N - 1;
		n_edges = 2 * gaps;
	}

	void solve()
	{
		int defi{ L - (1 << gaps) };
		for (int bit{ 0 }; defi >= (1 << bit); bit++)
			if (defi & (1 << bit))
				++n_edges;

		cout << N << " " << n_edges << endl;

		REP1O(i, N)
		{
			cout << i << " " << i + 1 << " " << 0 << endl;
			cout << i << " " << i + 1 << " " << (1 << (i - 1)) << endl;
		}

		int now{ 1 << gaps };
		for (int bit{ 21 }; bit >= 0; bit--)
		{
			if (defi & (1 << bit))
			{
				cout << bit + 1 << " " << N << " " << now << endl;
				now += (1 << bit);
			}

		}
		
	}

};


int main()
{
	D solution;
	solution.solve();

	return 0;
}