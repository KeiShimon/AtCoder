#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)
#define REPIT(i,x) for(auto i{(x).begin()}; i != (x).end(); i++) 

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<int> Vi;
typedef vector<vector<int>> VVi;

void debug();
void init();

string s, t;
ll ns, nt;
VVi nxt;

int main()
{
	init();

	ll ans = 0;
	int i = 0;

	for (char c : t)
	{
		i %= (ns >> 1);
		c -= 'a';

		if (nxt[i][c] > ns)
		{
			cout << -1 << endl;
			return 0;
		}

		ans += nxt[i][c] - i;
		i = nxt[i][c];
	}

	cout << ans << endl;
}

void debug()
{

	REP(j, 26)
		cout << setw(4) << char(j + 'a');
	cout << endl;

	REP(i, ns)
	{
		REP(j, 26)
			cout << setw(4) << nxt[i][j];
		cout << endl;
	}
}

void init()
{
	cin >> s >> t;
	ns = SZ(s);
	nt = SZ(t);

	s += s;
	ns <<= 1;
	nxt.resize(ns + 1, Vi(26, ns + 1));

	RREP(i, ns)
	{
		REP(j, 26)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i] - 'a'] = i + 1;
	}

	debug();
}

