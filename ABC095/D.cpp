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

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;

typedef pair<ll, ll> tup;


class D {
	ll n, c;
	vector<ll> pos;
	vector<ll> val;
	vector<tup> clock_memo;
	vector<tup> counter_memo;

public:
	D()
	{
		cin >> n >> c;
		pos.resize(n + 1);
		val.resize(n);
		clock_memo.resize(n+1);
		counter_memo.resize(n+1);
		clock_memo[n] = MP(0, 0);
		counter_memo[n] = MP(0, -1);
		pos[n] = 0;

		REP(i, n)
			cin >> pos[i] >> val[i];
	}

	void debug()
	{
		cout << "clockwise debug..." << endl;
		REP(i, n)
		{
			cout << "you can use upto index " << i << " : ";
			cout << "max_val = " << clock_memo[i].first << ", (index " << clock_memo[i].second << ")" << endl;
		}

		cout << endl << "counterclockwise debug..." << endl;
		REP(i, n)
		{
			cout << "You can use upto index " << i << " : ";
			cout << "max_val = " << counter_memo[i].first << ", (index " << counter_memo[i].second << ")" << endl;
		}

	}

	void solve()
	{
		ll ans{ 0 };
		ll tmp, ma, now;
		ll maxi;

		// clockwise
		tmp = ma = 0;
		now = 0; maxi = -1;
		REP(i, n)
		{
			tmp += (val[i] - (pos[i] - now));
			if (chmax(ma, tmp))
				maxi = i;
			//cout << "visiting " << pos[i] << " from " << now << endl;
			//cout << "tmp = " << tmp << endl;
			clock_memo[i] = MP(ma, maxi);
			now = pos[i];
		}

		// counterclockwise
		tmp = ma = 0;
		now = c;
		maxi = -1;
		RREP(i, n)
		{
			tmp += (val[i] - (now - pos[i]));
			if (chmax(ma, tmp))
				maxi = i;
			counter_memo[i] = MP(ma, maxi);
			now = pos[i];
		}

		REP(i, n)
		{
			ll val_clock{ clock_memo[i].F };
			ll id_clock{ clock_memo[i].S };
			ll d_clock;
			if (id_clock == -1)
				d_clock = 0;
			else
				d_clock = pos[id_clock];

			ll val_counter{ counter_memo[id_clock + 1].F };
			ll id_counter{ counter_memo[id_clock + 1].S };

			ll d_counter;
			if (id_counter == -1)
				d_counter = 0;
			else
				d_counter = c - pos[id_counter];

			tmp = val_clock + val_counter - min(d_clock, d_counter);
			chmax(ans, tmp);
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