#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;

const int dx[4] = { -1,  0 };
const int dy[4] = {  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

using namespace std;

typedef pair<int, int> pii;

class C {
	int n;
	int ans{ 0 };
	vector<pii> red;
	vector<pii> queries;
	vector<bool> matched;

public:
	C()
	{
		cin >> n;
		red.reserve(n);
		queries.reserve(n);
		matched.resize(n, false);

		int y, x;
		REP(i, n)
		{
			cin >> y >> x;
			red.emplace_back(MP(y, x));
		}
		REP(i, n)
		{
			cin >> y >> x;
			queries.emplace_back(MP(y, x));
		}
	}

	void search(const int& sy, const int& sx)
	{
		if (!sx || !sy)
			return;

		REP(i, n)
		{

			if (red[i].second < sx && red[i].first < sy && !matched[i])
			{
				ans++;
				matched[i] = true;
				return;
			}

		}

	}


	void solve()
	{
		sort(ALL(queries));
		sort(ALL(red), [](const pii& left, const pii& right) { return (left.second > right.second); });

		REP(i, n)
			search(queries[i].first, queries[i].second);

		cout << ans << endl;

	}
};

int main()
{

	C solution;
	solution.solve();

	return 0;
}