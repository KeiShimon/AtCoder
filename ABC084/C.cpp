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
	int n;
	vector<vector<int>> info;
public:
	C()
	{
		cin >> n;
		info.resize(n, vector<int>(3));

		REP(i, n)
			cin >> info[i][0] >> info[i][1] >> info[i][2];

	}
	void solve()
	{
		REP(i, n)
		{
			int t{ 0 };

			for (int j{ i }; j < n - 1; j++)
			{
				if (t < info[j][1])
					t = info[j][1];
				else
					t = info[j][1] + (t - info[j][1] + info[j][2] - 1) / info[j][2] * info[j][2];
				t += info[j][0];
			}

			cout << t << endl;

		}

	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}