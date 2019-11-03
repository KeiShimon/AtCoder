#include <cmath>
#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef int64_t ll;

inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

template <class T>
inline double eucladian(T ax, T ay, T bx, T by) { return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }

int sx, sy, gx, gy, t, v, max_d;
int n;

int main()
{
	cin >> sx >> sy >> gx >> gy >> t >> v >> n;
	max_d = v * t;

	REP(_i, n)
	{
		double d = 0;
		int x, y; cin >> x >> y;
		d += eucladian(x, y, sx, sy);
		d += eucladian(x, y, gx, gy);

		if (d <= max_d)
		{
			YES();
			return 0;
		}
	}

	NO();
}
