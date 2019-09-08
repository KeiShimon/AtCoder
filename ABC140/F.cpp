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

typedef pair<int, int> tup;

class QF {
	int n;
	deque<tup> parents;
	vector<int> nodes;

public:
	QF()
	{
		cin >> n;
		nodes.resize((1 << n));

		REP(i, 1 << n)
			cin >> nodes[i];
	}
	void solve()
	{
		sort(ALL(nodes));

		parents.PB(MP(nodes.back(), n));
		nodes.pop_back();

		while (!nodes.empty())
		{

			tup current{ parents.front() };
			parents.pop_front();
			int n_nextgen{ current.S - 1 };

			REP(i, current.S)
			{
				int child{ nodes.back() };
				nodes.pop_back();
				if (current.F == child)
				{
					cout << "No" << endl;
					return;
				}

				if (n_nextgen)
					parents.PB(MP(child, n_nextgen--));
			}
		}

		cout << "Yes" << endl;
	}
};


int main()
{
	QF solution;
	solution.solve();

	return 0;
}