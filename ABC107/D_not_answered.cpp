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

// 1-d BIT
template <class T>
struct BIT {
private:
	vector<T> bit;
	int n;

public:
	// constructors
	BIT(int n);
	BIT();
	void init(int n);

	// 1-indexed
	inline void add(int idx, T val);

	// sum for [1, idx] (1-indexed)
	inline T sum(int idx);

	// sum for [left, right) (1-indexed)
	inline T sum(int left, int right);

	T operator[](int i);

};


////////// 1-d BIT implementation //////////

// default constructor
template <class T>
BIT<T>::BIT()
	: BIT(0)
{}

// constructor
template <class T>
BIT<T>::BIT(int n)
	: bit(n + 1, (T)0), n{ n }
{}

// initializer
template <class T>
void BIT<T>::init(int n)
{
	bit.resize(n + 1, 0);
	this->n = n;
}


// 1-indexed
template <class T>
inline void BIT<T>::add(int idx, T val)
{
	for (int i{ idx }; i <= n; i += i & (-i))
		bit[i] += val;
}

// sum for [1, idx] (1-indexed)
template <class T>
inline T BIT<T>::sum(int idx)
{
	int ret{ 0 };
	for (; idx > 0; idx -= idx & (-idx))
		ret += bit[idx];

	return ret;
}


// sum for [left, right) (1-indexed)
template <class T>
inline T BIT<T>::sum(int left, int right)
{
	return sum(right - 1) - sum(left - 1);
}


template <class T>
T BIT<T>::operator[](int i)
{
	return sum(i, i + 1);
}


////////// END of 1-d BIT implementation //////////



class D {
	int n;
	vector<int> a;

public:
	D()
	{
		cin >> n;
		a.resize(n);
		REP(i, n)
			cin >> a[i];
	}

	bool check(int x)
	{
		BIT<int> bit(n * 2);

		int tot{ n + 1 };
		int sm{ 0 };

		bit.add(tot, 1);

		REP(i, n)
		{

			if (x >= a[i])
				++tot;
			else
				--tot;

			sm += bit.sum(tot - 1);
			bit.add(tot, 1);

		}
		return sm > n * (n + 1) / 2 - sm;
	}

	void solve()
	{
		int l{ 0 };
		int r = 2100000;

		while (r - l > 1)
		{
			//cout << l << " " << r << endl;

			int mid{ (l + r) / 2 };

			if (check(mid))
				r = mid;
			else
				l = mid;
		}

		cout << r << endl;

	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}
