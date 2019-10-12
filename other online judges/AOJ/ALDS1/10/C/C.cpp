#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

#define PB push_back
#define SZ(x) ((int)(x).size())

using namespace std;

typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<vector<int> > VVi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }

int n;
Vs vs, vt;

int main()
{
	cin >> n;
	REP(_i, n)
	{
		string s, t;
		cin >> s >> t;
		vs.PB(s);
		vt.PB(t);
	}

	REP(_i, n)
	{
		string& s = vs[_i];
		string& t = vt[_i];
		
		VVi dp(SZ(s) + 1, Vi(SZ(t) + 1, 0));

		REP(i, SZ(s))
			REP(j, SZ(t))
		{
			chmax(dp[i + 1][j + 1], dp[i][j + 1]);
			chmax(dp[i + 1][j + 1], dp[i + 1][j]);
			if (s[i] == t[j])
				chmax(dp[i + 1][j + 1], dp[i][j] + 1);
		}

		cout << dp[SZ(s)][SZ(t)] << endl;
	}


}