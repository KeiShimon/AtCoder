#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class B {
	vector<string> S;
public:
	void solve()
	{
		S.resize(3);
		cin >> S[0] >> S[1] >> S[2];

		for (int i{ 0 }; i < 3; i++)
			reverse(S[i].begin(), S[i].end());

		int player{ 0 }, nextPlayer;

		while (true)
		{
			if (S[player].empty()) break;
			else
			{
				nextPlayer = S[player].back() - 'a';
				S[player].pop_back();
				player = nextPlayer;
			}
		}

		cout << (char)(player + 'A') << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}