#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
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

const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const int MOD = 1000000007;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }


#include <map>
#include <iomanip>

const ll mask = 1LL << 63;

struct compare {
	bool operator()(const pair<ll, ll>& left, const pair<ll, ll>& right) const
	{
		if (!(left.first & mask) && !(left.second & mask)) // left is at 1st-quadrant
		{
			if (right.first & mask || right.second & mask) return true;
			else return (ll)left.second * right.first < (ll)left.first * right.second;
		}
		else if ((left.first & mask) && !(left.second & mask)) // left is at 2nd-quadrant
		{
			if (!(right.first & mask) && !(right.second & mask)) return false;
			else if ((right.first & mask) && !(right.second & mask)) return (ll)left.second * right.first < (ll)left.first * right.second;
			else return true;
		}
		else if (left.first & mask) // left is at 3rd-quadrant
		{
			if (!(right.second & mask)) return false;
			else if (right.first & mask) return (ll)left.second * right.first < (ll)left.first * right.second;
			else return true;
		}
		else
		{
			if (!(right.second & mask)) return false;
			else if (right.first & mask) return false;
			else return (ll)left.second * right.first < (ll)left.first * right.second;
		}
	}
};

map<pair<ll, ll>, ll, compare> vec;

template <class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
inline double eucladianDistance(ll vx, ll vy) { return sqrt(vx * vx + vy * vy); }

int main()
{
	int n; cin >> n;
	REP(_i, n)
	{
		ll x, y, g;
		cin >> x >> y;
		if (x && y) g = gcd(abs(x), abs(y));
		else if (x) g = abs(x);
		else if (y) g = abs(y);
		else continue;

		vec[pair<ll, ll>(x / g, y / g)] += g;
	}

	double ans = 0;
	for (auto va = vec.begin(); va != vec.end(); va++)
	{
		ll vx = va->first.first * va->second;
		ll vy = va->first.second * va->second;
		auto ort = vec.end();

		for (auto vb = vec.begin(); vb != vec.end(); vb++)
		{
			if (va == vb) continue;

			ll inner = va->first.first * vb->first.first + va->first.second * vb->first.second;
			if (inner > 0)
			{
				vx += vb->first.first * vb->second;
				vy += vb->first.second * vb->second;
			}
			else if (inner == 0)
			{
				if (ort == vec.end())
					ort = vb;
				else if (ort->second < vb->second)
					ort = vb;
			}
		}

		double d = eucladianDistance(vx, vy);
		chmax(ans, d);

		if (ort != vec.end())
		{
			vx += ort->first.first * ort->second;
			vy += ort->first.second * ort->second;
		}

		d = eucladianDistance(vx, vy);
		chmax(ans, d);
	}

	cout << setprecision(22) << ans << endl;
}
