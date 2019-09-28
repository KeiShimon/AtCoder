#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> pll;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template <class T>
inline double eucladian(T ax, T ay, T bx, T by) { return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }

vector<pll> engines;
int n;

void init()
{
	cin >> n;
	int zr = 0;
	REP(_i, n)
	{
		ll x, y; cin >> x >> y;
		if (!x && !y) // remove (0, 0)
		{
			++zr; continue;
		}
		engines.PB(pll(y, x));
	}

	n -= zr; // remove (0, 0)

	// sort by angle : use atan2 in <cmath>
	// theta = atan2(y,x)
	sort(ALL(engines), [](pll& left, pll& right){ return atan2(left.first, left.second) < atan2(right.first, right.second); });
}

int main()
{
	init();

	double ans = 0;

	REP1C(k, n) // how many engines ?
	{
		REP(i, n) // choose engines start idx
		{
			ll vx = 0, vy = 0;
			for (int j = i; j < min(n, i + k); ++j)
			{
				vy += engines[j].first;
				vx += engines[j].second;
			}

			if (n - i < k) // if not enough engines
			{
				for (int j = 0; j < (k - (n - i)); ++j)
				{
					vy += engines[j].first;
					vx += engines[j].second;
				}
			}
			chmax(ans, eucladian((ll)0, (ll)0, vx, vy));
		}
	}

	cout << setprecision(21) << ans << endl;
}
