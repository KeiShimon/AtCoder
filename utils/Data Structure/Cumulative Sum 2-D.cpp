#include "template.h"


template <class T>
struct CumSum2D {
private:
	const int h, w;
	vector<vector<T>> data;
public:
	CumSum2D(int h, int w) : data(h + 1, vector<T>(w + 1, (T)0)), h{ h + 1 }, w{ w + 1 } {}
	void add(int i, int j, T val) { if ((i + 1) < h && (j + 1) < w) data[i + 1][j + 1] += val; }
	void cumulate() { REP1O(i, h) REP1O(j, w) data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1]; }

	// [s, g) , s : btm-left, g : top-right
	T get(int si, int sj, int gi, int gj) { return data[gi][gj] + data[si][sj] - data[gi][sj] - data[si][gj]; }
};