#include <vector>

using namespace std;

// 1-d BIT
template <class Cls>
struct BIT {
private:
	vector<Cls> bit;
	int n;

public:
	// constructors
	BIT(int n);
	BIT();
	void init(int n);

	// 1-indexed
	void add(int idx, Cls val); 
	
	// sum for [1, idx] (1-indexed)
	Cls sum(int idx);

	// sum for [left, right) (1-indexed)
	Cls sum(int left, int right);

};


////////// 1-d BIT implementation //////////

// default constructor
template <class Cls>
BIT<Cls>::BIT()
	: BIT(0)
{}

// constructor
template <class Cls>
BIT<Cls>::BIT(int n)
	: bit(n + 1, 0), n{ n }
{}

// initializer
template <class Cls>
void BIT<Cls>::init(int n)
{
	bit.resize(n + 1, 0);
	this->n = n;
}


// 1-indexed
template <class Cls>
void BIT<Cls>::add(int idx, Cls val)
{
	for (int i{ idx }; i <= n; i += i & (-i))
		bit[i] += val;
}

// sum for [1, idx] (1-indexed)
template <class Cls>
Cls BIT<Cls>::sum(int idx)
{
	int ret{ 0 };
	for (int i{ idx }; i > 0; i -= i & (-i))
		ret += bit[i];

	return ret;
}


// sum for [left, right) (1-indexed)
template <class Cls>
Cls BIT<Cls>::sum(int left, int right)
{
	return sum(right - 1) - sum(left - 1);
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
