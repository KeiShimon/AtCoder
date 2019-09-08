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

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class C {
	int n;
	vector<int> b;
public:
	C()
	{
		cin >> n;
	}
	void solve()
	{
		int ans{ 0 };

		int last;
		int current;

		cin >> last;
		ans = last;

		if (n > 2)
			REP(i, n - 1)
			{
				cin >> current;

				ans += min(last, current);

				last = current;
			}
		
		else
		{
			ans += last;
		}

		cout << ans << endl;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}