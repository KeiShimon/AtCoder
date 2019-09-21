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
	int n;

public:
	BIT(int n);
	BIT();
	void init(int n);

	// 1-indexed
	void add(int idx, T val);

	// sum for [1, idx] (1-indexed)
	T sum(int idx);

	// sum for [l, r) (1-indexed)
	T sum(int left, int right);

	T operator[](int i);
};

int n;
vi va;
ll n_totsect;

void init()
{
	cin >> n;
	n_totsect = (ll)n * ((ll)n + 1) / 2;
	va.resize(n);
	REP(i, n)
		cin >> va[i];
}

bool check(int x)
{
	BIT<ll> bit(2 * n + 3);
	ll n_sect = 0;
	int sum = 0;
	const int offset = n + 1;

	bit.add(offset, 1);

	REP(i, n)
	{
		sum += (va[i] <= x) ? 1 : -1;
		n_sect += bit.sum(sum + offset);
		bit.add(sum + offset, 1);
	}

	if (n_sect > n_totsect / 2)
		return true;
	else
		return false;
}

int main()
{
	init();

	int ng = 0, ok = 1 << 30;
	while (ng < ok)
	{
		int md = (ok + ng) / 2;
		if (check(md)) ok = md;
		else ng = md;
	}

	cout << ok << endl;
}

////////// 1-d BIT implementation //////////

// default constructor
template <class T> BIT<T>::BIT() : BIT(0) {}

// constructor
template <class T> BIT<T>::BIT(int n) : data(n + 1, (T)0), n{ n } {}

// initializer
template <class T> void BIT<T>::init(int n) { data.resize(n + 1, (T)0); this->n = n; }

// add method (1-indexed)
template <class T> void BIT<T>::add(int idx, T val) { for (; idx <= n; idx += idx & (-idx)) data[idx] += val; }

// sum for [1, idx] (1-indexed)
template <class T> T BIT<T>::sum(int idx) { T ret{ 0 }; for (; idx > 0; idx -= idx & (-idx)) ret += data[idx]; return ret; }

// sum for [l, r) (1-indexed)
template <class T> T BIT<T>::sum(int left, int right) { return sum(right - 1) - sum(left - 1); }

template <class T> T BIT<T>::operator[](int i) { return sum(i) - sum(i - 1); }

////////// END of 1-d BIT implementation //////////
