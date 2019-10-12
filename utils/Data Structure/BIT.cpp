#include "template.h"

template <class T>
struct BIT {
private:
	vector<T> data;
	int ma;
	int maid;

public:
	// it can handle [0, n]
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


////////// 1-d BIT implementation //////////

// it can handle [0, n]
template <class T> inline BIT<T>::BIT(int n) : data(n + 2, (T)0), ma{ n }, maid{ n + 1 } {}
template <class T> inline BIT<T>::BIT() : BIT(1000) {}
template <class T> inline void BIT<T>::init(int n) { data.assign(n + 2, (T)0); this->ma = n; this->maid = n + 1; }

template <class T> inline void BIT<T>::add(int a, T val) { for (++a; a <= maid; a += a & (-a)) data[a] += val; }

// sum up to a (close-end)
template <class T> inline T BIT<T>::sum(int a) { T ret{ 0 }; for (++a; a > 0; a -= a & (-a)) ret += data[a]; return ret; }

// sum for [l, r)
template <class T> inline T BIT<T>::sum(int left, int right) { return sum(right - 1) - sum(left - 1); }

template <class T> inline T BIT<T>::operator()(int a) { if ( 0 <= a && a <= ma) return sum(a) - sum(a - 1); }

////////// END of 1-d BIT implementation //////////
