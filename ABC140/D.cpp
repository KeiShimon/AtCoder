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

typedef int64_t int64;
typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;


class D {
	int n, k;
	string s;
	vector<int> cum;
public:
	D()
	{
		cin >> n >> k;
		cin >> s;
		cum.resize(n);

		if (s[0] == 'L')
			cum[0] = 0;
		else if (s[1] == 'R')
			cum[0] = 1;
		else
			cum[0] = 0;

		for (int i{ 1 }; i <= n - 2; i++)
		{
			if (s[i] == 'L')
			{
				if (s[i - 1] == 'L')
					cum[i] = cum[i - 1] + 1;
				else
					cum[i] = cum[i - 1];
			}
			else
			{
				if (s[i + 1] == 'R')
					cum[i] = cum[i - 1] + 1;
				else
					cum[i] = cum[i - 1];
			}
		}

		if (s[n - 1] == 'R')
			cum[n - 1] = cum[n - 2];
		else
		{
			cum[n - 1] = cum[n - 2] ;
			if (s[n - 2] == 'L')
				cum[n - 1] += 1;
			}

	}

	void debug()
	{
		REP(i, n)
			cout << cum[i] << " ";
		cout << endl;
	}

	int calcleft(int left)
	{
		if (left == 0)
			return 0;
		else
			return cum[left -1];
	}

	int calcright(int right)
	{
		if (right == n)
			return 0;
		else
			return cum[n - 1] - cum[right - 1];
	}

	void solve()
	{
		int flip{ 0 };
		int left{ 0 };
		int right{ 1 };
		int ans{ cum[n - 1] };

		while (right < n)
		{

			bool flag{ false };
			while (right < n)
			{
				if (s[right] != s[left])
				{
					if (!flag)
					{
						if (flip >= k)
							break;
						else
						{
							++flip;
							flag = true;
						}
					}
				}
				else
					flag = false;

				++right;
			}
			right = min(right, n);

			chmax(ans, calcleft(left) + calcright(right) + (right - left - 1));

				//cout << left << " " << right << endl;

			++left;
			while (s[left - 1] == s[left] && left < right - 1)
				++left;
		}

		chmax(ans, calcleft(left) + calcright(right) + (right - left - 1));
		//	cout << left << " " << right << endl;

		cout << ans << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}