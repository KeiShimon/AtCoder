#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

typedef int64_t ll;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

void init();

bool containsZero = false;
int n, k;
vector<ll> vs;

int main()
{
	init();

	if (containsZero)
	{
		cout << n << endl;
		return 0;
	}

	int ans = 0;

	int l = 0, r = 0;
	ll cur = 1;
	while (l < n && r <= n)
	{
		if (l == r)
		{
			cur = vs[r++];
			continue;
		}

		if (cur <= k)
		{
			chmax(ans, r - l);
			if (r == n)
				break;
			cur *= vs[r++];
		}
		else
		{
			cur /= vs[l++];
		}
	}

	cout << ans << endl;
}


void init()
{
	cin >> n >> k;
	vs.resize(n);
	REP(i, n)
	{
		cin >> vs[i];
		if (!vs[i])
		{
			containsZero = true;
			break;
		}
	}
}