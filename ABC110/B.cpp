#include <iostream>

using namespace std;

class B {
	int N, M, X, Y;
public:
	void solve()
	{
		int maxX{ -101 }, minY{ 101 };
		int x, y;

		for (int i{ 0 }; i < N; i++)
		{
			cin >> x;
			if (x > maxX) maxX = x;
		}
		for (int i{ 0 }; i < M; i++)
		{
			cin >> y;
			if (y < minY) minY = y;
		}

		if ((maxX < Y) && (maxX < minY) && (X < minY))
			cout << "No War" << endl;
		else cout << "War" << endl;
	}

	B()
	{
		cin >> N >> M >> X >> Y;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}