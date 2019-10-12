#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#include <functional>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++)

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

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

void init();

int query[2501], res[2501];
int n, q;
CumSum2D<int> cum(50, 50);

int main()
{
	init();

	REP1C(target, n * n)
	{
		int lim = (int)(sqrt(target));

		REP1C(h, lim)
		{
			if (target % h)
				continue;

			int w = target / h;

			if (h > n || w > n)
				continue;

			int tmp = 0;
			REPC(i, n - h)
				REPC(j, n - w)
				chmax(tmp, cum.get(i, j, i + h, j + w));

			swap(h, w);

			REPC(i, n - h)
				REPC(j, n - w)
				chmax(tmp, cum.get(i, j, i + h, j + w));

			chmax(res[target], tmp);

			swap(h, w);
		}
	}

	REP1C(i, n * n)
		chmax(res[i], res[i - 1]);

	REP(i, q)
		cout << res[query[i]] << endl;
}

void init()
{
	cin >> n;
	REP(i, n) REP(j, n)
	{
		int d; cin >> d;
		cum.add(i, j, d);
	}

	cum.cumulate();

	cin >> q;
	REP(i, q)
		cin >> query[i];
}
