#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#include <unordered_map>
#include <unordered_set>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
void SWAP(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
void SWAP(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

using namespace std;

vector<int> primes;
void generatePrimes(int n);

class D {
	int n;
	static const int MAX{ 555555 };
public:
	D()
	{
		cin >> n;
		generatePrimes(MAX);
		reverse(ALL(primes));
	}

	void declare(const vector<int>& vec)
	{
		REP(i, n - 1)
			cout << vec[i] << " ";
		cout << vec.back() << endl;
	}

	void solve()
	{
		vector<int> ans;

		while (ans.size() < n)
		{
			int nxt{ primes.back() };
			primes.pop_back();

			if (1 == (nxt % 5))
				ans.PB(nxt);
		}

		// declare(ans);

		REP(i, SZ(ans))
			cout << ans[i] << " ";
		cout << endl;
	}
};


int main()
{
	D solution;
	solution.solve();

	return 0;
}

void generatePrimes(int n)
{

	if (n < 2)
		return;

	int k{ 3 };

	if (primes.empty())
		primes.push_back(2);
	else if (primes.size() != 1)
		k = primes[primes.size() - 1] + 2;

	bool flag{ true };

	for (; k <= n; k += 2)
	{
		flag = true;
		int limit = (int)ceil(sqrt(k)) + 1;
		int sz{ (int)primes.size() };
		for (int i{ 0 }; i < sz && primes[i] < limit; i++)
		{
			if (!(k % primes[i]))
			{
				flag = false;
				break;
			}
		}

		if (flag)
			primes.push_back(k);
	}

	flag = true;
	k = n;
	for (int d : primes)
	{
		if (!(k % d))
		{
			flag = false;
			break;
		}
	}

	if (flag)
		primes.push_back(k);
}

