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


bool is_prime(const int64_t n)
{
	if (n == 1)
		return false;

	if (n == 2 || n == 3)
		return true;

	if (!(n & 1) || !(n % 3))
		return false;

	for (int64_t i{ 5 }; i * i <= n; i += 6)
		if (!(n % i) || !(n % (i + 2))) // 6n-1 or 6n+1
			return false;

	return true;
}


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
	: bit(n + 1, 0), n{ n }
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
	for (; idx <= n; idx += idx & (-idx))
		bit[idx] += val;
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
	int q;
	static const int MAX{ 100002 };
	int memo[MAX + 1];
public:
	D()
	{
		cin >> q;

		REP(i, MAX + 1)
			memo[i] = -1;

	}
	void solve()
	{
		BIT<int> bit(MAX);

		bit.add(3, 1);

		for (int x{ 3 }; x < MAX / 2; x += 2)
		{
			int y{ 2 * x - 1 };

			if (is_prime(x) && is_prime(y))
				bit.add(y, 1);
		}

		int l, r;
		REP(_q, q)
		{
			cin >> l >> r;

			if (memo[l - 1] == -1)
				memo[l - 1] = bit.sum(l - 1);
			if (memo[r] == -1)
				memo[r] = bit.sum(r);

			cout << memo[r] - memo[l - 1] << endl;

		}

	}

	void debug()
	{

	}

};


int main()
{
	D solution;
	solution.solve();

	return 0;
}