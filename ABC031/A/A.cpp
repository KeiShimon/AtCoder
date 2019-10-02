#include <iostream>

using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int main()
{
	int a, d; cin >> a >> d;

	int ans = 0;
	chmax(ans, (a + 1) * d);
	chmax(ans, a * (d + 1));

	cout << ans << endl;
}
