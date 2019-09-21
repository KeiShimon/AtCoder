#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

typedef int64_t ll;
typedef pair<int, ll> P;

int n;
ll c;
vector<ll> val, pos;

vector<P> toleft, toright;

void init()
{
	cin >> n >> c;

	val.resize(n + 1, 0);
	pos.resize(n + 1, 0);
	REP1C(i, n) { cin >> pos[i] >> val[i]; }

	toleft.resize(n + 1);
	toright.resize(n + 1);
	toright[0] = toleft[0] = P(0, 0);
}

int main()
{
	init();
	ll best, tmp;

	best = tmp = 0;
	REP1C(i, n)
	{
		tmp += val[i];
		if (chmax(best, tmp - pos[i]))
			toright[i] = P(i, best);
		else
			toright[i] = toright[i - 1];
	}

	best = tmp = 0;
	for (int i = n; i >= 1; --i)
	{
		tmp += val[i];
		if (chmax(best, tmp - 2 * (c - pos[i])))
			toleft[i] = P(i, best);
		else
		{
			if (i == n)
				toleft[i] = P(0, 0);
			else
				toleft[i] = toleft[i + 1];
		}
	}

	ll ans = 0;
	REP1C(i, n)
	{
		chmax(ans, toright[i].second);
		if (toright[i].first != n)
			chmax(ans, toright[i].second + toleft[toright[i].first + 1].second);
	}

	best = tmp = 0;
	REP1C(i, n)
	{
		tmp += val[i];
		if (chmax(best, tmp - 2 * pos[i]))
			toright[i] = P(i, best);
		else
			toright[i] = toright[i - 1];
	}

	best = tmp = 0;
	for (int i = n; i >= 1; --i)
	{
		tmp += val[i];
		if (chmax(best, tmp - (c - pos[i])))
			toleft[i] = P(i, best);
		else
		{
			if (i == n)
				toleft[i] = P(0, 0);
			else
				toleft[i] = toleft[i + 1];
		}
	}

	REP1C(i, n)
	{
		chmax(ans, toleft[i].second);
		if (toleft[i].first != 0)
			chmax(ans, toleft[i].second + toright[toleft[i].first - 1].second);
	}

	cout << ans << endl;
}
