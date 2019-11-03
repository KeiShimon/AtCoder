#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, curMax{ -1 }, tmpint, totPopulation{ 0 };
	string candidateCityName, tmpstr;

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
