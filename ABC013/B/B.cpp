#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int ans = abs(b - a);
	ans = min(ans, b + 10 - a);
	ans = min(ans, a + 10 - b);
	cout << ans << endl;
}
