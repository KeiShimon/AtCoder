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

typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

using namespace std;


class D {
	int n;
	static const int MAX_BIT{ 28 };
	vector<int> arr_a;
	vector<vector<int>> countbits;

public:
	D()
	{
		countbits.resize(2, vector<int>(MAX_BIT, 0));
		cin >> n;
		arr_a.resize(n);

		REP(i, n)
			cin >> arr_a[i];

		int tmp;
		REP(i, n)
		{
			cin >> tmp;

			for (int bit{ 0 }; bit < MAX_BIT; bit++)
			{
				if (tmp & (1 << bit))
					++countbits[1][bit];
				else
					++countbits[0][bit];
			}
		}

	}

	void debug(const vector<vector<int>>& v)
	{
		REP(i, 2)
		{
			REP(j, v.size())
				cout << v[i][j] << " ";
			cout << endl;
		}

	}

	void solve()
	{

		int ans{ 0 };

		debug(countbits);

		for (int a : arr_a)
		{
			int tmpxor{ 0 };
			vector<vector<int>> tmpCountBits{ countbits };

			REPC(bit, MAX_BIT)
			{
				int a_bit{ 0 };
				if (a & (1 << bit))
					a_bit = 1;

				int digit_contribution{ 0 };
				if (a_bit)
				{
					if (tmpCountBits[0][bit] & 1)
						digit_contribution = 1;
					if (tmpCountBits[1][bit] & 1)
						if (bit + 1 <= MAX_BIT)
							tmpCountBits[1][bit + 1] += 1;
				}
				else
				{
					if (tmpCountBits[1][bit] & 1)
						digit_contribution = 1;
				}

				tmpxor += (digit_contribution << bit);
			}

			ans ^= tmpxor;
		}
		
		cout << ans << endl;
	}
};

int main()
{

	D solution;
	solution.solve();

	return 0;
}