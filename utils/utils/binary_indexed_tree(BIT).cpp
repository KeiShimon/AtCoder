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


////////// END of 1d BIT implementation //////////

