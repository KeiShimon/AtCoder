#include <iostream>

using namespace std;

typedef int64_t ll;

template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const ll linf = 1LL << 60;

ll N;

int main()
{
	cin >> N;
	ll ans = linf;
	for (ll i = 1; i * i <= N; ++i)
	{
		if (N % i)
			continue;

		ll j = N / i;

		chmin(ans, i + j - 2);
	}

	cout << ans << endl;
}
