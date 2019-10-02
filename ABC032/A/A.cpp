#include <iostream>

using namespace std;

template <class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main()
{
	int a, b, n;
	cin >> a >> b >> n;

	int l = lcm(a, b);

	int ans = (n + l - 1) / l * l;

	cout << ans << endl;
}
