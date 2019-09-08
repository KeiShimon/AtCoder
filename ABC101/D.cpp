#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
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
	int k;
public:
	D()
	{
		cin >> k;
	}

	double calc(int x)
	{
		int div{ 0 };
		int tmp{ x };
		while (tmp)
		{
			div += tmp % 10;
			tmp /= 10;
		}

		return (double)x / div;
	}

	void test()
	{
		int testnum = 10000;

		for (int x{ testnum / 10 }; x < testnum; x++)
		{
			bool flag{ true };
			double x_calc{ calc(x) };

			for (int y{ x + 1 }; y < testnum; y++)
			{
				if (x_calc > calc(y))
				{
					flag = false;
					break;
				}
			}

			if (flag)
				cout << x << endl;
		}
	}

	bool checkSnuke(string a, string b)
	{
		int div_a{ 0 }, div_b{ 0 };
		REP(i, SZ(a))
		{
			div_a += a[i] - '0';
			div_b += b[i] - '0';
		}

		return (stoll(a) / div_a < stoll(b) / div_b) ? true : false;

	}

	string genNextSnuke(const int check, const string& nines)
	{
		string nextSnuke{to_string(check)};
		int n{ SZ(nextSnuke) };

		REP(i, n)
			if (nextSnuke[n - 1 - i] != '9')
			{
				nextSnuke[n - 1 - i] = '9';
				return nextSnuke + nines;
			}

		return nextSnuke + nines;

	}

	void solve()
	{

		if (k <= 9)
		{
			REP(i, k)
				cout << i + 1 << endl;
			return;
		}

		REP(i, 9)
			cout << i + 1 << endl;

		ll answered{ 9 };
		int n_digits{ 2 };
		while (answered < k)
		{
			int fixNine;
			int freeDigits;

			if (n_digits == 2)
			{
				fixNine = 1;
				freeDigits = 1;
			}
			else if (n_digits <= 4)
			{
				fixNine = 2;
				freeDigits = n_digits - 2;
			}
			else
			{
				freeDigits = 3;
				fixNine = n_digits - 3;
			}

			string nines;
			REP(i, fixNine)
				nines.PB('9');

			int limit{ pow(10, freeDigits) - 1 };
			for (int check{ pow(10, freeDigits - 1) }; check <= limit && answered < k; check++)
			{
				if (!((check - limit / 10) % (limit / 10 + 1)))
				{
					cout << to_string(check) + nines << endl;
					answered++;
					continue;
				}

				string check_str{ to_string(check) + nines };
				if (checkSnuke(check_str, genNextSnuke(check, nines)))
				{
					cout << check_str << endl;
					answered++;
				}
			}
			n_digits++;
		}
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}