#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <string.h>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t int64;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

class C {
	int d, target;
	int mask{ 0 };
	vector<vector<int>> problems;
public:
	C()
	{
		cin >> d >> target;
		problems.resize(d, vector<int>(2));
		
		REP(i, d)
		{
			mask |= (1 << i);
			cin >> problems[i][0] >> problems[i][1];
			problems[i][1] += 100 * (i + 1) * problems[i][0];
		}
	}

	void solve()
	{

		int ans{ 2000 };
		int sum;
		int n_questions;

		for (int bit{ 0 }; bit < (1 << d); bit++)
		{
			sum = n_questions = 0;

			for (int b{ 0 }; b < d; b++)
				if (bit & (1 << b))
				{
					sum += problems[b][1];
					n_questions += problems[b][0];
				}

			if (sum >= target)
			{
				chmin(ans, n_questions);
				continue;
			}
			else
			{
				int notUsed{ mask ^ bit };
				// look for highest bit that is zero
				for (int b{ d - 1 }; b >= 0; b--)
				{
					if (notUsed & (1 << b))
					{
						// find out how many questions we need to the target
						int needMore{ ceil(((double)target - sum) / 100 / (b + 1)) };

						// if the number does not exceed existing qustions update ans
						if (needMore <= problems[b][0])
							chmin(ans, n_questions + needMore);

						break;
					}
				}
			}
		}

		cout << ans << endl;
	}
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}