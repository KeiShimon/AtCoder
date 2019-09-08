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

using namespace std;

class B {
	string s, t;
	int n;
public:
	B()
	{
		cin >> s >> t;
		n = SZ(s);
	}

	string rotate(const string& s, const int d)
	{
		string ret;
		ret.resize(n);

		REP(i, n)
		{
			if (i + d >= n)
			{
				ret[i + d - n] = s[i];
			}
			else
			{
				ret[i + d] = s[i];
			}
		}

		return ret;
	}
	void solve()
	{
		bool flag{ false };
		REP(d, n)
		{
			if (t == rotate(s, d))
			{
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}