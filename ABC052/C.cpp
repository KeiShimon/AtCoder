#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string.h>
#include <tuple>
#include <vector>

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

using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tupiii;
typedef tuple<ll, ll, ll> tuplll;

const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;
const int MOD = 1000000007;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void swap(ll& a, ll& b) { a ^= b; b ^= a; a ^= b; }
inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

#include <unordered_map>

int n;
vector<int> primes;
void generatePrimes(int n);
unordered_map<int, int> um;

void init()
{
	cin >> n;
	generatePrimes(n);
}


int main()
{
	init();

	for (int p : primes)
	{
		int tmp = p;
		auto it = um.insert(MP(p, 0)).first;
		
		while (tmp <= n)
		{
			it->second += n / tmp;
			tmp *= p;
		}
	}

	ll ans = 1;
	for (auto it = um.begin(); it != um.end(); it++)
	{
		ans = (ans * (ll)(it->second + 1)) % MOD;
	}

	cout << ans << endl;
}


void generatePrimes(int n)
{

	const int originPrimes[10]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

	for (int i{ 0 }; i < 10; i++)
	{
		if (originPrimes[i] > n)
			return;

		primes.push_back(originPrimes[i]);
	}

	bool flag{ true };

	for (int k{ 31 }; k <= n; k += 2)
	{
		if (!(k % 3))
			continue;

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
	for (int d : primes)
	{
		if (!(n % d))
		{
			flag = false;
			break;
		}
	}

	if (flag)
		primes.push_back(n);

}
