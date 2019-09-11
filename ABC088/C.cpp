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


class C {
	int c[3][3];
public:
	C()
	{
		REP(i, 3)
			REP(j, 3)
			cin >> c[i][j];
	}
	void solve()
	{
		REP(i, 2)
		{
			if (c[i][0] - c[i + 1][0] == c[i][1] - c[i + 1][1] && c[i][1] - c[i + 1][1] == c[i][2] - c[i + 1][2])
				continue;
			else
			{
				cout << "No" << endl;
				//cout << "when comparing row " << i << " and row" << i + 1 << endl;
				return;
			}
		}

		REP(j, 2)
		{
			if (c[0][j] - c[0][j + 1] == c[1][j] - c[1][j + 1]&& c[1][j] - c[1][j + 1] == c[2][j] - c[2][j + 1])
				continue;
			else
			{
				cout << "No" << endl;
				//cout << "when comparing col " << j << "and col" << j + 1 << endl;
				return;
			}

		}

		cout << "Yes" << endl;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}