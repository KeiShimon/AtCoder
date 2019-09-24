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

template <class T>
struct BIT {
private:
	vector<T> data;
	int ma;
	int maid;

public:
	// [0, n] is the value you can deal
	BIT(int n);
	BIT();
	void init(int n);

	void add(int a, T val);

	// sum up to a (close-end)
	T sum(int a);

	// sum for [l, r)
	T sum(int left, int right);

	T operator()(int a);

	void print()
	{
		REP1C(i, maid) cout << sum(i, i + 1) << ",";
		cout << endl;
	}
};

int n;
vi va, va_sorted;
ll n_totsect;

void init()
{
	cin >> n;
	n_totsect = (ll)n * ((ll)n + 1) / 2;
	va.resize(n); va_sorted.resize(n);
	REP(i, n)
	{
		cin >> va[i];
		va_sorted[i] = va[i];
	}
	sort(ALL(va_sorted));
}

bool check(int x)
{
	BIT<ll> bit(2 * n);
	ll n_sect = 0;
	int sum = 0;

	bit.add(n, 1);

	REP(i, n)
	{
		sum += (va[i] <= x) ? 1 : -1;
		n_sect += bit.sum(sum + n - 1);
		bit.add(sum + n, 1);
	}

	return n_sect > n_totsect / 2;
}

int main()
{
	init();

	int ng = 0, ok = n - 1;
	while (ok - ng > 1)
	{
		int md = (ok + ng) / 2;
		if (check(va_sorted[md]))
			ok = md;
		else
			ng = md;
	}

	cout << va_sorted[ok] << endl;
}

////////// 1-d BIT implementation //////////

// [0, n] is the value you can deal
template <class T> BIT<T>::BIT(int n) : data(n + 2, (T)0), ma{ n }, maid{ n + 1 } {}
template <class T> BIT<T>::BIT() : BIT(1000) {}
template <class T> void BIT<T>::init(int n) { data.assign(n + 2, (T)0); this->ma = n; this->maid = n + 1; }

template <class T> void BIT<T>::add(int a, T val) { for (++a; a <= maid; a += a & (-a)) data[a] += val; }

// sum up to a (close-end)
template <class T> T BIT<T>::sum(int a) { T ret{ 0 }; for (++a; a > 0; a -= a & (-a)) ret += data[a]; return ret; }

// sum for [l, r)
template <class T> T BIT<T>::sum(int left, int right) { return sum(right - 1) - sum(left - 1); }

template <class T> T BIT<T>::operator()(int a) { if (0 <= a && a <= ma) return sum(a) - sum(a - 1); }

////////// END of 1-d BIT implementation //////////
