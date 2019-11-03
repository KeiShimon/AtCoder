#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int a, b;

int main()
{
	cin >> a >> b;

	cout << max(0, a - b - b) << endl;
}
