#include <iostream>

using namespace std;

class D {
	int n, m;
public:
	D()
	{
		cin >> n >> m;
	}
	void solve()
	{

		int div;
		int over = m / 2 + 1;
		for (div = n; div < over; div++)
		{
			if ((m % div) == 0)
				break;
		}

		if (div == over) cout << 1 << endl;
		else cout << m / div << endl;
	}

};


int main()
{
	D solution;
	solution.solve();

	return 0;
}