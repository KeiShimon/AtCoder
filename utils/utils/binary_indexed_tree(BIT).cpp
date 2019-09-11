#include <vector>

using namespace std;

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




//  2-d BIT
struct BIT_2D {
private:
	vector<vector<int>> bit;
	int m, n;

public:
	BIT_2D();
	BIT_2D(int m, int n, bool initialize_one = false);

	void add(int i, int j, int val);
	int sum(int i, int j);
};


////////// 2-d BIT implementation //////////

BIT_2D::BIT_2D() : BIT_2D(0, 0) {}
BIT_2D::BIT_2D(int m, int n, bool initialize_one = false)
{
	this->m = m;
	this->n = n;

	if (!initialize_one)
		bit.resize(m + 1, vector<int>(n + 1, 0));
	else
	{
		bit.resize(m + 1, vector<int>(n + 1));
		for(int y{1}; y <= m; y++)
			for (int x{ 1 }; x <= n; x++)
				bit[y][x] = (y & (-y)) + (x & (-x));
	}
}

void BIT_2D::add(int i, int j, int val)
{
	for (int y{ i }; y <= m; y += y & (-y))
		for (int x{ j }; x <= n; x += x & (-x))
			bit[y][x] += val;

}

int BIT_2D::sum(int i, int j)
{
	int ret{ 0 };
	for (int y{ i }; y > 0; y -= y & (-y))
		for (int x{ j }; x > 0; x -= x & (-x))
			ret += bit[y][x];

	return ret;
}


////////// END of 2-d BIT implementation //////////
