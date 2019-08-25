#include <iostream>
#include <vector>
#include <string>

using namespace std;

class B {
	int N, M;
	vector<string> imgA, imgB;
public:
	void solve()
	{
		imgA.resize(N);
		imgB.resize(M);

		for (int i{ 0 }; i < N; i++)
			cin >> imgA[i];
		for (int i{ 0 }; i < M; i++)
			cin >> imgB[i];

		for (int dv{ 0 }; dv <= N - M; dv++)
		{
			for (int dh{ 0 }; dh <= N - M; dh++)
			{
				bool flag = true;
				for (int y{ 0 }; y < M; y++)
				{
					if (imgA[dv + y].substr(dh, M) != imgB[y])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					cout << "Yes" << endl;
					return;
				}
			}
		}

		cout << "No" << endl;
	}

	B() { cin >> N >> M; }
};


int main()
{
	B solution;
	solution.solve();

	return 0;
 }