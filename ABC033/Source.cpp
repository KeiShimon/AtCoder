#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class A {
	int N;

public:
	void solve()
	{
		cin >> N;

		bool flag{1};
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
};


class B {
	int N, curMax{ -1 }, tmpint, totPopulation{ 0 };
	string candidateCityName, tmpstr;

public:
	void solve()
	{
		cin >> N;

		for (int i{ 0 }; i < N; i++)
		{
			cin >> tmpstr >> tmpint;
			totPopulation += tmpint;
			if (tmpint > curMax)
			{
				curMax = tmpint;
				candidateCityName = tmpstr;
			}
		}

		if (floor((double)totPopulation / 2.0) < curMax) cout << candidateCityName << endl;
		else cout << "atcoder" << endl;

	}
};


int main()
{
	A solution;
	solution.solve();

	return 0;
}