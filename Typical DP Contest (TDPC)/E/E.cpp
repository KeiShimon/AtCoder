#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)

using namespace std;

typedef int64_t ll;
const int MOD = 1000000007;

////// Mod int //////
struct mint {
	ll x;
	mint() :x(0) {}
	mint(ll x) :x((x% MOD + MOD) % MOD) {}
	// mint(ll x):x(x){}
	mint& fix() { x = (x % MOD + MOD) % MOD; return *this; }
	mint operator-() const { return mint(0) - *this; }
	mint& operator+=(const mint& a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
	mint& operator-=(const mint& a) { if ((x += MOD - a.x) >= MOD) x -= MOD; return *this; }
	mint& operator*=(const mint& a) { (x *= a.x) %= MOD; return *this; }
	mint operator+(const mint& a)const { return mint(*this) += a; }
	mint operator-(const mint& a)const { return mint(*this) -= a; }
	mint operator*(const mint& a)const { return mint(*this) *= a; }
	bool operator<(const mint& a)const { return x < a.x; }
	bool operator==(const mint& a)const { return x == a.x; }
};
istream& operator>>(istream& i, mint& a) { i >> a.x; return i; }
ostream& operator<<(ostream& o, const mint& a) { o << a.x; return o; }
typedef vector<mint> Vm;

/////////////////////

string n;
int d;
Vm dp_less, dp_exact;

int main()
{
	cin >> d >> n;
	dp_less.resize(d, 0);
	dp_exact.resize(d, 0);

	dp_exact[0] = 1;

	for (char c : n)
	{
		int dig = c - '0';
		Vm newdp(d, 0);
		
		REP(i, d)
			REP(x, 10)
			newdp[(i + x) % d] += dp_less[i];

		REP(i, d)
			if (dp_exact[i].x > 0)
			{
				REP(x, dig)
					newdp[(i + x) % d] += 1;

				dp_exact[i] = 0;
				dp_exact[(i + dig) % d] = 1;
				break;
			}

		swap(newdp, dp_less);
	}

	mint ans = dp_exact[0] + dp_less[0] - 1;
	cout << ans << endl;
}
