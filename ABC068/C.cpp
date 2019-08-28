#include <iostream>
#include <vector>

using namespace std;

class C {
	int N, M;
	vector<vector<int>> edges;
public:
	void solve()
	{

		if (bruteforce()) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;

	}

	bool bruteforce()
	{

		for (int moveOne : edges[0])
		{
			for (int moveTwo : edges[moveOne])
			{
				if (moveTwo == N - 1)
					return true;
			}
		}

		return false;
	}

	C()
	{
		cin >> N >> M;
		edges.resize(N);

		int a, b;
		for (int i{ 0 }; i < M; i++)
		{
			cin >> a >> b;
			a--; b--;

			edges[a].push_back(b);
			edges[b].push_back(a);
		}
	}
};

int main()
{
	C solution;
	solution.solve();

	return 0;
}