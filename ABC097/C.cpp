#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#include <set>

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

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;

class C {
	string s;
	int k;
public:
	C()
	{
		cin >> s >> k;
	}

	void solve()
	{
		set<string> st;

		REP(left, SZ(s))
		{
			for (int right{ left + 1 }; right < SZ(s) + 1; right++)
			{

				if (SZ(st) < k)
				{
					st.insert(s.substr(left, right - left));
				}
				else
				{
					string sub{ s.substr(left, right - left) };
					if (sub < *(--st.end()))
					{
						if (!st.count(sub))
						{
							st.erase(--st.end());
							st.emplace(sub);
						}
					}
				}
			}
		}

		cout << *(--st.end()) << endl;

	}
};

int main()
{
	C solution;
	solution.solve();

	return 0;
}