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

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


class C {
	int count[26];
	int n;
public:
	C()
	{
		memset(count, 0, sizeof count);
		cin >> n;
		string name;
		REP(i, n)
		{
			cin >> name;
			++count[name[0] - 'A'];
		}

	}
	void solve()
	{
		ll ans{ 0 };
		
		const int idx[5]{ 'M' - 'A', 'A' - 'A' ,'R' - 'A' ,'C' - 'A' ,'H' - 'A' };

		for (int i{ 0 }; i < 3; i++)
			for (int j{ i + 1 }; j < 4; j++)
				for (int k{ j + 1 }; k < 5; k++)
					ans += (ll)count[idx[i]] * count[idx[j]] * count[idx[k]];

		cout << ans << endl;
		

	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}