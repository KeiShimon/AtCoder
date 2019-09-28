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

using namespace std;


class C {
	int n;
	vector<int> h;
public:
	C()
	{
		cin >> n;
		h.resize(n);
		REP(i, n)
			cin >> h[i];
	}
	void solve()
	{
		int ans{ 0 };
		int streak{ 0 };
		int i{ 0 };

		while (i < n - 1)
		{
			if (h[i] >= h[i + 1])
			{
				streak++;
				i++;
				chmax(ans, streak);
			}

			else
			{
				streak = 0;
				i++;
			}
		}

		cout << ans << endl;
	}
};
//
//
//int main()
//{
//	C solution;
//	solution.solve();
//
//	return 0;
//}