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


class D {
	int n;
	vector<int> a;

public:
	D()
	{
		cin >> n;

		a.resize(n);
		REP(i, n)
			cin >> a[i];

	}

	void solve()
	{
		ll ans{ 0 };
		int right{ 1 };
		ll sum{ a[0] };

		for (int left{ 0 }; left < n; left++)
		{
			while (right < n && !(a[right] & sum))
			{
				sum += a[right];
				++right;
			}

			ans += ((ll)right - left);
			sum -= a[left];
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