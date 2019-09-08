#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string.h>
#include <vector>
#include <tuple>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef tuple<int, int, int> tupiii;


// 1-indexed 1-d BIT
template <class Cls>
struct BIT {
private:
	vector<Cls> bit;
	int n;

public:
	// constructors
	BIT(int n);
	BIT();

	// initializer
	void init(int n);

	// 1-indexed
	void add(int idx, Cls val);

	// sum for [1, idx] (1-indexed)
	Cls sum(int idx);

	// sum for [left, right) (1-indexed)
	Cls sum(int left, int right);
};


class D {
	int n, m, q;
	BIT<int> bit;
	vector<tupiii> queries;
	vector<int> ans;

public:
	D()
	{
		cin >> n >> m >> q;
		queries.reserve(n + m);
		ans.resize(q + 1);
		bit.init(n);

		int l, r;
		REP(i, m)
		{
			cin >> l >> r;
			queries.PB(make_tuple(l, r, 0));
		}

		REP(i, q)
		{
			cin >> l >> r;
			queries.PB(make_tuple(l, r, i + 1));
		}
	}

	void solve()
	{
		sort(ALL(queries), [](tupiii left, tupiii right) { return (get<1>(left) != get<1>(right)) ? (get<1>(left) < get<1>(right)) : (get<2>(left) < get<2>(right)); });
		
		//cout << "print queries" << endl;
		//REP(i, (int)queries.size())
		//	cout << get<0>(queries[i]) << " " << get<1>(queries[i]) << " " << get<2>(queries[i]) << endl;
		//cout << "END print queries" << endl << endl;

		REP(i, m + q)
		{
			int left{ get<0>(queries[i]) };
			int right{ get<1>(queries[i]) };
			int question{ get<2>(queries[i]) };

			if (question)
			{
				ans[question] = bit.sum(left, right + 1);
			}
			else
			{
				bit.add(left, 1);
			}
		}

		for (int i{ 1 }; i <= q; i++)
			cout << ans[i] << endl;
	}
};

int main()
{
	D solution;
	solution.solve();

	return 0;
}

////////// 1-d BIT implementation //////////

// constructor
template <class Cls>
BIT<Cls>::BIT()
	: BIT(0)
{}

template <class Cls>
BIT<Cls>::BIT(int n)
	: bit(n + 1, 0), n{n}
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
