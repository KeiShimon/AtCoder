#include "template.h"

// 1-d BIT
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
	inline void add(int idx, T val);

	// sum for [1, idx] (1-indexed)
	inline T sum(int idx);

	// sum for [left, right) (1-indexed)
	inline T sum(int left, int right);

	T operator[](int i);

};


////////// 1-d BIT implementation //////////

// default constructor
template <class T> BIT<T>::BIT() : BIT(0) {}

// constructor
template <class T> BIT<T>::BIT(int n) : data(n + 1, 0), n{ n } {}

// initializer
template <class T> void BIT<T>::init(int n) { data.resize(n + 1, 0); this->n = n; }


// add method (1-indexed)
template <class T> inline void BIT<T>::add(int idx, T val) { for (; idx <= n; idx += idx & (-idx)) data[idx] += val; }

// sum for [1, idx] (1-indexed)
template <class T> inline T BIT<T>::sum(int idx) { T ret{ 0 }; for (; idx > 0; idx -= idx & (-idx)) ret += data[idx]; return ret; }


// sum for [left, right) (1-indexed)
template <class T> inline T BIT<T>::sum(int left, int right) { return sum(right - 1) - sum(left - 1); }

// operator []
template <class T> T BIT<T>::operator[](int i) { return sum(i) - sum(i - 1); }


////////// END of 1-d BIT implementation //////////

