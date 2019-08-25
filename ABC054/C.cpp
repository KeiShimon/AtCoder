#include <iostream>
#include <vector>

using namespace std;

class C {
	int N, M;
	vector<vector<int>> edges;
	int allNodesAreVisited{ 0 };
public:
	void solve_dfs()
	{
		edges.resize(N);
		int a, b;
		for (int i{ 0 }; i < M; i++)
		{
			cin >> a >> b;
			a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		for (int shift{ 0 }; shift < N; shift++) allNodesAreVisited |= (1 << shift);

		cout << dfs(0, 0) << endl;

	}

	int dfs(const int& node, int status)
	{
		if (status & (1 << node)) return 0; // check if multiple visits

		status |= (1 << node);
		if (status == allNodesAreVisited) return 1; // check if all nodes are visited

		int possiblePaths{ 0 };

		for (int nextNode : edges[node])
			possiblePaths += dfs(nextNode, status);

		return possiblePaths;
	}

	C()
	{
		cin >> N >> M;
	};
};


int main()
{
	C solution;
	solution.solve_dfs();

	return 0;
}