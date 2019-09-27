#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define PB push_back
#define MP make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef double dbl;
typedef vector<bool> Vb;
typedef vector<char> Vc;
typedef vector<double> Vd;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<string> Vs;
typedef vector<vector<int>> VVi;
typedef vector<vector<ll>> VVl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }
inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

const int inf = 1 << 30;
const ll linf = 1LL << 60;
const int MOD = 1000000007;

int n, k;
string s;
vector<int> cum;

void init()
{
	cin >> n >> k;
	cin >> s;
	cum.resize(n);

	if (s[0] == 'L')
		cum[0] = 0;
	else if (s[1] == 'R')
		cum[0] = 1;
	else
		cum[0] = 0;

	for (int i{ 1 }; i <= n - 2; i++)
	{
		if (s[i] == 'L')
		{
			if (s[i - 1] == 'L')
				cum[i] = cum[i - 1] + 1;
			else
				cum[i] = cum[i - 1];
		}
		else
		{
			if (s[i + 1] == 'R')
				cum[i] = cum[i - 1] + 1;
			else
				cum[i] = cum[i - 1];
		}
	}

	if (s[n - 1] == 'R')
		cum[n - 1] = cum[n - 2];
	else
	{
		cum[n - 1] = cum[n - 2];
		if (s[n - 2] == 'L')
			cum[n - 1] += 1;
	}

}

int calcleft(int left)
{
	if (left == 0)
		return 0;
	else
		return cum[left - 1];
}

int calcright(int right)
{
	if (right == n)
		return 0;
	else
		return cum[n - 1] - cum[right - 1];
}

int main()
{
	init();

	int flip{ 0 };
	int left{ 0 };
	int right{ 1 };
	int ans{ cum[n - 1] };

	while (right < n)
	{

		bool flag{ false };
		while (right < n)
		{
			if (s[right] != s[left])
			{
				if (!flag)
				{
					if (flip >= k)
						break;
					else
					{
						++flip;
						flag = true;
					}
				}
			}
			else
				flag = false;

			++right;
		}
		right = min(right, n);

		chmax(ans, calcleft(left) + calcright(right) + (right - left - 1));

		//cout << left << " " << right << endl;

		++left;
		while (s[left - 1] == s[left] && left < right - 1)
			++left;
	}

	chmax(ans, calcleft(left) + calcright(right) + (right - left - 1));
	//	cout << left << " " << right << endl;

	cout << ans << endl;
}
