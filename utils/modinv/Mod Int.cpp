#include "template.h"

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