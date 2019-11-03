#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

const double pi = acos(-1);
const double eps = 1e-10;
double a, b, x;
double area;

bool check_1(double d)
{
	double t = tan(d * pi / 180);
	double tmp = b * b / 2 / t;

	return x <= tmp + eps;
}

bool check_2(double d)
{
	double t = tan(d * pi / 180);
	double tmp = area - a * a / 2 * t;

	return x <= tmp + eps;
}

int main()
{
	cin >> a >> b >> x;
	x /= a;
	area = a * b;

	if (x <= a * b / 2)
	{
		double ng = 180-eps;
		double ok = 0;
		REP(i, 100)
		{
			auto mid = (ng + ok) / 2;
			if (check_1(mid))
				ok = mid;
			else
				ng = mid;
		}

		cout << setprecision(9) << ok << endl;
		return 0;
	}

	double ng = 180 - eps;
	double ok = 0;

	REP(i, 100)
	{
		auto mid = (ng + ok) / 2;
		if (check_2(mid))
			ok = mid;
		else
			ng = mid;
	}

	cout << setprecision(10) << ok << endl;

}
