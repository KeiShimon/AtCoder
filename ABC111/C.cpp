#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


class C {
	int n;
public:
	void solve()
	{
		int v;
		vector<int> odd(100001, 0);
		vector<int> even(100001, 0);

		for (int i{ 0 }; i < n; i++)
		{
			cin >> v;
			if (i & 1)
				++odd[v];
			else
				++even[v];
		}

		int max_odd{ 0 }, max_even{ 0 };
		int second_odd{ 0 }, second_even{ 0 };
		int ans;

		for (int i{ 0 }; i <= 100001; i++)
		{
			if (odd[max_odd] < odd[i])
			{
				second_odd = max_odd;
				max_odd = i;
			}
			else if (odd[second_odd] < odd[i])
			{
				second_odd = i;
			}
			if (even[max_even] < even[i])
			{
				second_even = max_even;
				max_even = i;
			}
			else if (even[second_even] < even[i])
			{
				second_even = i;
			}
		}

		if (max_odd != max_even)
		{
			ans = accumulate(odd.begin(), odd.end(), 0) - odd[max_odd];
			ans += accumulate(even.begin(), even.end(), 0) - even[max_even];
		}

		else
		{
			int tmpans;
			tmpans = accumulate(odd.begin(), odd.end(), 0) - odd[max_odd];
			tmpans += accumulate(even.begin(), even.end(), 0) - even[second_even];

			ans = accumulate(odd.begin(), odd.end(), 0) - odd[second_odd];
			ans += accumulate(even.begin(), even.end(), 0) - even[max_even];

			if (tmpans < ans) ans = tmpans;
		}

		cout << ans << endl;
	}

	C()
	{
		cin >> n;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}
