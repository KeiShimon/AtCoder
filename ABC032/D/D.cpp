#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<ll> Vl;
typedef vector<vector<ll>> VVl;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const ll linf = 1LL << 60;

void init();
ll solve_set1();
ll solve_set2();
ll solve_set3();

int n, w;
Vl vv, vw;
ll max_v = 0, max_w = 0;

int main()
{
	init();

	ll ans;
	if (max_w <= 1000)
		ans = solve_set2();
	else if (max_v <= 1000)
		ans = solve_set3();
	else
		ans = solve_set1();

	cout << ans << endl;
}

void init()
{
	cin >> n >> w;
	vv.resize(n);
	vw.resize(n);
	REP(i, n)
	{
		cin >> vv[i] >> vw[i];
		chmax(max_v, vv[i]);
		chmax(max_w, vw[i]);
	}
}

// maximize value against weight
ll solve_set2()
{
	Vl dp(w + 1, -1);
	dp[0] = 0;

	REP(i, n)
	{
		Vl newdp(w + 1, -1);
		REPC(j, w)
		{
			if (dp[j] == -1)
				continue;
			chmax(newdp[j], dp[j]);
			if (j + vw[i] <= w)
				chmax(newdp[j + vw[i]], dp[j] + vv[i]);
		}

		swap(dp, newdp);
	}

	ll ret = 0;
	REPC(i, w) chmax(ret, dp[i]);
	return ret;
}

// minimize weight against val
ll solve_set3()
{
	ll sum_v = accumulate(ALL(vv), 0LL);
	ll sum_w = accumulate(ALL(vw), 0LL);

	Vl dp(sum_v + 1, linf);
	dp[sum_v] = sum_w;

	REP(i, n)
	{
		REPC(j, sum_v)
			if (dp[j] != linf)
				chmin(dp[j - vv[i]], dp[j] - vw[i]);
	}

	int ret = 0;
	REPC(i, sum_v)
		if (dp[i] <= w)
			chmax(ret, i);

	return (ll)ret;
}

ll solve_set1()
{
	int n_a = n / 2;
	int n_b = n - n_a;

	Vl vva, vvb, vwa, vwb;
	REP(i, n_a)
	{
		vva.PB(vv[i]);
		vwa.PB(vw[i]);
	}
	for (int i = n_a; i < n; ++i)
	{
		vvb.PB(vv[i]);
		vwb.PB(vw[i]);
	}

	// weight, val
	map<ll, ll> res_a;

	REP(mask, 1 << n_a)
	{
		ll v_a = 0, w_a = 0;
		REP(bit, n_a)
			if (mask & (1 << bit))
			{
				v_a += vva[bit];
				w_a += vwa[bit];
			}

		auto it = res_a.find(w_a);
		if (it == res_a.end())
			res_a.insert(MP(w_a, v_a));
		else
			res_a[w_a] = max(res_a[w_a], v_a);
	}

	ll ret = 0;

	REP(mask, 1 << n_b)
	{
		ll v_b = 0, w_b = 0;
		REP(bit, n_b)
			if (mask & (1 << bit))
			{
				v_b += vvb[bit];
				w_b += vwb[bit];
			}

		for (auto it = res_a.begin(); it != res_a.end() && it->first + w_b <= w; ++it)
			chmax(ret, it->second + v_b);
	}

	return ret;
}