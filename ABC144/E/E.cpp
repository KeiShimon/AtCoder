#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;
typedef vector<ll> Vl;

const ll MAX_A = 1e6;
Vl F, A;
ll K;
int N;

void init()
{
	cin >> N >> K;
	A.resize(N);
	F.resize(N);

	REP(i, N) cin >> A[i];
	REP(i, N) cin >> F[i];

	sort(ALL(A), greater<>());
	sort(ALL(F));
}

bool check(ll t)
{
	ll x = 0;
	REP(i, N)
	{
		ll a = A[i] - t / F[i];
		x += max((ll)0, a);
	}

	return x <= K;
}

int main()
{
	init();
	ll ng = -1, ok = MAX_A * MAX_A * 2+ 1;
	while (ok - ng > 1)
	{
		auto mid = (ng + ok) / 2;

		if (check(mid))
			ok = mid;
		else
			ng = mid;
	}

	cout << ok << endl;
}
