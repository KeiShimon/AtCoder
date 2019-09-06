#include <vector>

using namespace std;

// 1-indexed 1-d BIT
struct BIT {
private:
	vector<int> bit;
	int n;

public:
	BIT(int n, bool initialize_one = false);
	BIT();

	void add(int idx, int val);
	int sum(int idx);
};


// 1-indexed 2-d BIT
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


////////// 1-d BIT implementation //////////

// constructor
BIT::BIT() : BIT(0) {}
BIT::BIT(int n, bool initialize_one = false)
{
	this->n = n;
	if (!initialize_one)
		bit.resize(n + 1, 0);
	else
	{
		bit.resize(n + 1);
		for (int i{ 1 }; i <= n; i++)
			bit[i] = (i & (-i));
	}
}

// add some value to some index
void BIT::add(int idx, int val)
{
	for (int i{ idx }; i <= n; i += i & (-i))
		bit[i] += val;
}

// get sum for [1, idx]
int BIT::sum(int idx)
{
	int ret{ 0 };
	for (int i{ idx }; i > 0; i -= i & (-i))
		ret += bit[i];

	return ret;
}


////////// END of 1-d BIT implementation //////////


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
