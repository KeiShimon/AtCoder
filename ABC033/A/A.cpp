#include <iostream>

using namespace std;

int main() {
	int N;

	cin >> N;

	bool flag{ 1 };
	int digit{ N % 10 };
	N /= 10;
	for (int i{ 0 }; i < 3; i++)
	{
		if (N % 10 != digit)
		{
			flag = 0;
			break;
		}

		N /= 10;
	}

	if (flag) cout << "SAME" << endl;
	else cout << "DIFFERENT" << endl;
	}
