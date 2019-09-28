#include <iostream>
#include <set>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef int64_t ll;
typedef vector<bool> Vb;
typedef vector<int> Vi;

vector<vector<int>> g;
Vb visiting, done;
int n, m;

void init()
{
	cin >> n >> m;
	g.resize(n);

	visiting.resize(n, false);
	done.resize(n, false);

	REP(i, m)
	{
		int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b);
	}
}

bool check(int v, const Vi& path)
{
	set<int> vertices(ALL(path));

	for (int v_inPath : path)
	{
		int cnt = 0;
		for (int u : g[v_inPath])
			if (vertices.count(u))
				++cnt;

		if (cnt > 1)
			return false;
	}
	return true;
}

vector<int> dfs(int v, Vi& path)
{
	Vi ret;

	if (g[v].empty())
		return ret;

	if (visiting[v])
	{
		auto it = path.begin();
		while (*it != v)
			++it;

		Vi loopPath(it, path.end());

		if (check(v, loopPath))
			return loopPath;
		else
			return ret;
	}

	path.push_back(v);
	visiting[v] = true;

	for (int adj : g[v])
	{
		ret = dfs(adj, path);
		if (!ret.empty())
			return ret;
	}

	path.pop_back();
	visiting[v] = false;
	done[v] = true;
	return ret;
}


int main()
{
	init();
	Vi v;

	REP(i, n)
	{
		if (done[i])
			continue;

		v.clear();
		Vi res = dfs(i, v);
		if (!res.empty())
		{
			cout << res.size() << endl;
			REP(j, res.size())
				cout << res[j] + 1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}
