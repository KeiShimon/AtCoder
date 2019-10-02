#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

#define PB push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

using namespace std;

void init();
bool check(int mask);

int n, k;
string ans[10], s[50];
vector<vector<int>> v;


int main()
{
	init();

	int mask = 0;
	REP(i, k)
		mask |= (1 << (2 * i));
	
	for (; mask < (1 << (2 * k)); ++mask)
		if (check(mask))
		{
			REP(i, k)
				cout << ans[i] << endl;
			return 0;
		}
}

bool check(int mask)
{
	vector<int> sz(k);
	REP(bit, k)
	{
		sz[bit] = (mask & 0b11);
		if (!sz[bit])
			return false;
		mask >>= 2;
	}

	REP(i, k) ans[i] = "";

	REP(i, n)
	{
		string cur = "";
		int j = 0;
		for (int x : v[i])
		{
			x -= 1;

			if (j + sz[x] > SZ(s[i]))
				return false;

			if (ans[x] == "")
				ans[x] = s[i].substr(j, sz[x]);

			j += sz[x];
			cur += ans[x];
		}

		if (cur != s[i])
			return false;
	}

	return true;
}

void init()
{
	cin >> k >> n;

	v.resize(n);

	REP(i, 10) ans[i] = "";

	REP(i, n)
	{
		int x;
		cin >> x >> s[i];

		while (x)
		{
			v[i].PB(x % 10);
			x /= 10;
		}
		reverse(ALL(v[i]));
	}
}
