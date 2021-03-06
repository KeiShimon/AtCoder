#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

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

using namespace std;

typedef int64_t int64;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


class B {
	int n;
public:
	B()
	{
		cin >> n;
	}
	void solve()
	{
		int ans{ 0 };

		for (int i{ 1 }; i <= n; i+= 2)
		{
			int cnt{ 0 };
			REP(j, n)
			{
				if (!(i % (j + 1)))
					cnt++;
			}
			if (cnt == 8)
				ans++;
		}

		cout << ans << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}