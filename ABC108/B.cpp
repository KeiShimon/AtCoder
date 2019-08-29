#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i > 0; i--)
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
	int x[4];
	int y[4];
public:
	B()
	{
		cin >> x[0] >> y[0] >> x[1] >> y[1];
	}
	void solve()
	{
		int vx{ x[1] - x[0] };
		int vy{ y[1] - y[0] };

		x[2] = x[1] - vy;
		y[2] = y[1] + vx;

		x[3] = x[2] - vx;
		y[3] = y[2] - vy;

		cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3] << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}