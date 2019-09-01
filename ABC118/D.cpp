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


class D {
	int n, m;
	int cost[10]{ 0,2,5,5,4,5,6,3,7,6 };
	vector<char> options;

public:

	D()
	{
		cin >> n >> m;
		options.resize(m);
		char a;

		REP(i, m)
		{
			cin >> a;
			options[i] = a;
		}
		sort(ALL(options), [this](const char& l, const char& r) { return (cost[l - '0'] == cost[r - '0']) ? (l > r) : (cost[l - '0'] < cost[r - '0']); });

	}

	bool chmax(string& a, const string& b)
	{
		if (SZ(a) < SZ(b))
		{
			a = b; return true;
		}

		else if (SZ(a) > SZ(b))
			return true;

		else
		{
			REP(i, SZ(a))
			{
				if (a[i] < b[i])
				{
					a = b;
					return true;
				}
			}
		}

		return false;
	}

	void solve()
	{


	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}