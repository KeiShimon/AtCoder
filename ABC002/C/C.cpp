#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define RREP(i,x) for(int i{ x - 1 }; i >= 0; i--)

int x[3], y[3];

int main()
{
	REP(i, 3) cin >> x[i] >> y[i];
	RREP(i, 3) x[i] -= x[0], y[i] -= y[0];

	double s = (x[1] * y[2] - x[2] * y[1]);
	s /= 2;
	s = abs(s);

	cout << setprecision(15) << s << endl;
}
