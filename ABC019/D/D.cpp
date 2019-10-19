#include <iostream>

using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int n, amax, ma;

int main()
{
	cin >> n;
	ma = -1;

	for (int i = 2; i <= n; ++i)
	{
		int dist;
		cout << "? " << 1 << " " << i << endl;
		cin >> dist;

		if (chmax(ma, dist))
			amax = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		int dist;
		cout << "? " << amax << " " << i << endl;
		cin >> dist;

		chmax(ma, dist);

	}

	cout << "! " << ma << endl;

}
