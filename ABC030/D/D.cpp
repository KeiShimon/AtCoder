#include <iostream>
#include <set>
#include <string>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

using namespace std;

const int inf = 1 << 30;

void init();

int n, a, k_int = inf;
string k;
vector<int> vb, firstn;

int main()
{
	init();

	firstn.resize(n + 1);
	int i = a;
	REPC(c, n)
	{
		firstn[c] = i;
		i = vb[i];
	}

	if (k_int <= n)
	{
		cout << firstn[k_int] << endl;
		return 0;
	}

	vector<int> loop{ i };
	do
	{
		i = vb[i];
		loop.push_back(i);
	} while (vb[i] != loop[0]);

	const int loop_size = loop.size();
	int path_size = 0;

	set<int> s(loop.begin(), loop.end());
	i = a;
	while (!s.count(i))
	{
		i = vb[i];
		++path_size;
	}

	int cnt_moves = 0;
	for (char c : k)
		cnt_moves = (10 * cnt_moves + c - '0') % loop_size;

	while (cnt_moves < path_size)
		cnt_moves += loop_size;

	cout << firstn[cnt_moves] << endl;
}

void init()
{
	cin >> n >> a >> k;
	vb.resize(n + 1);
	REP1C(i, n) cin >> vb[i];

	if (k.size() < 7)
		k_int = stoi(k);
}
