#include <iostream>
#include <unordered_set>

using namespace std;

class C {
	int N;
	unordered_set<int> us;
public:
	void solve()
	{
		int A;
		for (int i{ 0 }; i < N; i++)
		{
			cin >> A;
			if (!(us.insert(A).second))
			{
				us.erase(A);
			}
		}

		cout << us.size() << endl;
	
	}

	C() { cin >> N; }
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}