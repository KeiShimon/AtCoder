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


class C {
	int n, k;
	vector<int> left, right;
public:
	C()
	{
		cin >> n >> k;
		int tmp;
		REP(i, n)
		{
			cin >> tmp;
			if (tmp < 0)
				left.PB( -tmp);
			else
				right.PB(tmp);
		}
		sort(ALL(left));
	}
	void solve()
	{
		int ans{ (pow(10, 9)) };
		int cost_left, cost_right, use_right;
		int n_items_left{ SZ(left) }, n_items_right{ SZ(right) };

		if (n_items_right >= k)
			ans = right[k - 1];

		if (n_items_left >= 1)
		{
			REP(i, n_items_left)
			{

				use_right = k - i - 1;
				if (use_right > n_items_right)
					continue;

				if (use_right == 0)
				{
					chmin(ans, left[k - 1]);
					break;
				}

				if (i + 1 > k)
					break;

				cost_left = left[i];
				cost_right = right[use_right - 1];

				chmin(ans, 2 * cost_left + cost_right);
				chmin(ans, cost_left + 2 * cost_right);
			}
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