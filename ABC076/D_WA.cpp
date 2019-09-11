#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


class D {
	int n;
	int maxt{ 0 };
	vector<double> h;
	vector<vector<double>> tr;
	int w;
public:
	D()
	{
		cin >> n;
		tr.resize(n, vector<double>(2));

		REP(i, n)
		{
			int x;
			cin >> x;
			maxt += x;
			tr[i][0] = x;
		}

		REP(i, n)
			cin >> tr[i][1];

		w = 2 * maxt + 1;
		h.resize(w, (double)maxt / 2);
	}

	void left(int et, double ev)
	{
		//cout << "Calling left at time = " << et << " val = " << ev << endl;

		for (int t{ 2 * et }; t >= 0; t--)
		{
			double v{ ev + ((double)et * 2 - t) / 2 };
			//if (ev == 2)
			//	cout << "Making time =" << (double)t / 2 << " to height = " << v << endl;
			chmin(h[t], v);
		}
	}

	void right(int st, double sv)
	{
		for (int t{ 2 * st }; t <= maxt * 2; t++)
		{
			double v{ sv + ((double)t - (double)2 * st) / 2 };
			
			chmin(h[t], v);
		}
	}

	void horiozn(int st, int et, double v)
	{
		for (int t{ st * 2 }; t <= et * 2; t++)
			chmin(h[t], v);
	}

	void solve()
	{

		right(0, 0);
		left(maxt, 0);

		int t{ 0 };
		REP(i, n)
		{

			left(t, tr[i][1]);
			horiozn(t, t + tr[i][0], tr[i][1]);
			t += tr[i][0];
			right(t, tr[i][1]);
		}

		double ans{ 0 };

		REP(i, 2 * maxt)
		{
			ans += (h[i] + h[i + 1]);
		}

		ans /= 4;

		cout << ans << endl;

		//REP(i, w)
		//	cout << h[i] << " ";
		//cout << endl;
	}

};


int main()
{
	D solution;
	solution.solve();

	return 0;
}