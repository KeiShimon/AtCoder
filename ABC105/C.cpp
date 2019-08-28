#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class C {
	int N;
public:
	void solve()
	{
		ostringstream S;
		string ans;
		int quotient, remainder;

		if (N)
		{
			while (N)
			{
				quotient = N / (-2);
				remainder = N - (-2) * quotient;

				if (remainder == -1)
				{
					remainder = 1;
					quotient++;
				}

				S << remainder;
				N = quotient;
			}

			ans = S.str();
			reverse(ans.begin(), ans.end());
		}

		else ans = "0";

		cout << ans << endl;
	}

	C() { cin >> N; }
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}