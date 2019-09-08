#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>
#include <deque>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class C {
	int n;
	string s;
	vector<int> left_west, right_east;

public:
	C()
	{
		cin >> n >> s;
		left_west.resize(n, 0);
		right_east.resize(n, 0);
	}
	void solve()
	{
		int lw{ 0 }, re{ 0 };

		REP(i, n - 1)
		{
			if (s[i] == 'W')
				left_west[i + 1] = left_west[i] + 1;
			else
				left_west[i + 1] = left_west[i];

			if (s[n - i - 1] == 'E')
				right_east[n - i - 2] = right_east[n - i - 1] + 1;
			else
				right_east[n - i - 2] = right_east[n - i - 1];
		}

		//REP(i, n)
		//	cout << left_west[i] << " ";
		//cout << endl;
		//REP(i, n)
		//	cout << right_east[i] << " ";
		//cout << endl;


		int ans{ 400000 };

		REP(i, n)
			chmin(ans, left_west[i] + right_east[i]);

		cout << ans << endl;

	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}