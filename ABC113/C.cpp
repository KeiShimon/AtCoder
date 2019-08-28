#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ios>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;

class C {
	int N, M;
	vector<vector<int>> byPrefectureYears;
	vector<int> years;
	vector<int> prefs;

public:
	void solve()
	{
		for (int i{ 0 }; i < MAX; i++)
			sort(byPrefectureYears[i].begin(), byPrefectureYears[i].end());

		ostringstream oss;

		for (int i{ 0 }; i < M; i++)
		{
			oss.str("");
			oss << setfill('0') << right << setw(6) << prefs[i];
			oss << setfill('0') << right << setw(6) << (1 + (lower_bound(byPrefectureYears[prefs[i]].begin(), byPrefectureYears[prefs[i]].end(), years[i]) - byPrefectureYears[prefs[i]].begin()));
			cout << oss.str() << endl;
		}

	}

	C()
	{
		cin >> N >> M;
		years.resize(M);
		prefs.resize(M);
		byPrefectureYears.resize(MAX);

		for (int i{ 0 }; i < M; i++)
		{
			cin >> prefs[i] >> years[i];
			byPrefectureYears[prefs[i]].push_back(years[i]);
		}	
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}