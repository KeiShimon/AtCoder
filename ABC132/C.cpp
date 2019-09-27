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
};

int n;

void init()
{
	cin >> n;
}


int main()
{
	init();

	BIT<int> bit((int)1e5);

	REP(_i, n)
	{
		int d; cin >> d;
		bit.add(d, 1);
	}

	int ans = 0;
	REP1C(d, (int)1e5)
		if (bit.sum(d - 1) == n / 2)
			++ans;

	cout << ans << endl;

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
