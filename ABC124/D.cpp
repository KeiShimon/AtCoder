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

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class D {
	int n, MAX_ORDER;
	string s;
public:
	D()
	{
		cin >> n >> MAX_ORDER >> s;
	}
	void solve()
	{
		int ans{ 1 };
		int streak{ 1 };
		int n_order{ (s[0] == '0') ? 1 : 0 };
		int left{ 0 }, right{ 1 };
		char currentGroup{ s[0] };

		while (right < n)
		{
			if (left >= right)
			{
				if (left >= n)
					break;
				right = left + 1;
				n_order = (s[left] == '0') ? 1 : 0;
				currentGroup = s[left];
				continue;
			}

			if (s[right] != currentGroup)
			{
				if (s[right] == '0') // 1 -> 0
				{
					currentGroup = '0';
					if (n_order >= MAX_ORDER)
					{
						char last{ s[left++] };
						while (!(s[left] == '1' && last == '0') && left < right)
						{
							last = s[left++];
						}
					}
					else // (n_order < MAX_ORDER)
					{
						++n_order;
					}
				}
				else // (s[right] == '1') // 0 -> 1
				{
					currentGroup = '1';
				}
			}

			chmax(ans, right - left + 1);
			++right;
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