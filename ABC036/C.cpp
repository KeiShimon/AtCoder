#include <iostream>
#include <map>
#include <vector>

using namespace std;

class C {
	map<int, int> m;
	vector<int> a;
	int N;
public:
	void solve()
	{
		int i;
		for (i = 0; i < N; i++)
		{
			cin >> a[i];
			m.insert(make_pair(a[i], 0));
		}

		i = 0;
		for (auto it= m.begin(); it != m.end(); it++)
		{
			it->second = i++;
		}


		for (i = 0; i < N; i++)
			cout << m.find(a[i])->second << endl;

	}
	C() { cin >> N; a.resize(N); }
};


int main()
{
	C solution;
	solution.solve();

	return 0;
}