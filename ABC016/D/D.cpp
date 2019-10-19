#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

typedef int64_t ll;

struct Point {
	ll x, y;

	Point(int x, int y) : Point((ll)x, (ll)y) {}
	Point(ll x, ll y) : x{ x }, y{ y } {}
};

bool intersect(const Point& a1, const Point& a2, const Point& b1, const Point& b2)
{
	ll res_1 = (a1.x - a2.x) * (b1.y - a1.y) + (a1.y - a2.y) * (a1.x - b1.x);
	ll res_2 = (a1.x - a2.x) * (b2.y - a1.y) + (a1.y - a2.y) * (a1.x - b2.x);

	return ((res_1 ^ res_2) & (1LL << 63));
}

int main()
{
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	Point A(ax, ay), B(bx, by);

	int n; cin >> n;
	int cnt = 0;

	cin >> ax >> ay;
	int tmpx = ax, tmpy = ay;

	REP(_i, n - 1)
	{
		cin >> bx >> by;

		Point P(ax, ay), Q(bx, by);
		cnt += intersect(A, B, P, Q);

		ax = bx; ay = by;
	}

	{
		Point P(ax, ay), Q(tmpx, tmpy);
		cnt += intersect(A, B, P, Q);
	}

	cout << cnt / 2 + 1 << endl;
}
