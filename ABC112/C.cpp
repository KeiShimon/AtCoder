#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>

using namespace std;

class C {
	int N;
	int64_t record[100][3];
	int64_t nonZeroPoint[3];
public:
	void solve()
	{
		cout << helper() << endl;
	}

	string helper()
	{
		ostringstream oss;
		int64_t h, tmph;
		bool flag{ true };

		for (int cx{ 0 }; cx <= 100; cx++)
		{
			for (int cy{ 0 }; cy <= 100; cy++)
			{
				h = nonZeroPoint[2] + abs(nonZeroPoint[0] - cx) + abs(nonZeroPoint[1] - cy);
				if (h < 1)
					continue;

				flag = true;
				for (int i{ 0 }; i < N; i++)
				{
					tmph = h - abs(record[i][0] - cx) - abs(record[i][1] - cy);
					tmph = max((int64_t)0, tmph);
					if (record[i][2] != tmph)
					{
						flag = false;
						break;
					}
				}

				if (flag)
				{
					oss << cx << " " << cy << " " << h;
					return oss.str();
				}
			}
		}
	}
	
	C()
	{
		cin >> N;
		memset(record, 0, sizeof record);
		for (int i{ 0 }; i < N; i++)
			cin >> record[i][0] >> record[i][1] >> record[i][2];

		for (int i{ 0 }; i < N; i++)
		{
			if (record[i][2])
			{
				nonZeroPoint[0] = record[i][0];
				nonZeroPoint[1] = record[i][1];
				nonZeroPoint[2] = record[i][2];
				break;
			}
		}
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}