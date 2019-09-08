#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>

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
	int n, m;
	vector<int> a;
	unordered_map<int, int> um;

public:
	D()
	{
		cin >> n >> m;
		a.resize(n);
		REP(i, n)
			cin >> a[i];
	}

	inline int64_t comb2(const int n)
	{
		if (n < 2)
			return 0;

		return (int64_t)n * ((int64_t)n - 1) / 2;
	}

	void solve()
	{
		vector<int> cum(n + 1, 0);
		int zeros{ 0 };

		REP(i, n)
		{
			cum[i + 1] = (cum[i] + a[i]) % m;

			auto it{ um.find(cum[i + 1]) };
			if (it != um.end())
				(it->second)++;
			else
				um.insert(MP(cum[i + 1], 1));
		}

		int64_t ans{ 0 };

		for (auto it{ um.begin() }; it != um.end(); it++)
		{
			ans += comb2(it->second);
		}

		auto it{ um.find(0) };
		if (it != um.end())
			ans += it->second;

		cout << ans << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}