#include "template.h"

template <class T>
class CumulativeSum {
private:
	int n_elem;
	vector<T> data;

public:
	CumulativeSum(int n) : data(n + 1), n_elem{ n } {}
	void add(int i, T val) { if (i < n_elem) data[i + 1] += val; }
	void cumulate() { for (int i = 1; i <= n; ++i) data[i] += data[i - 1]; }
	T get(int l, int r) { if (0 <= l && r < n_elem) return data[r - 1] - data[l - 1]; }
};
