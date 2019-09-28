#include <iostream>
#include <set>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

using namespace std;

multiset<int> s;
int n;

int main()
{
	cin >> n;

	REP(_i, n)
	{
		int a; cin >> a;

		auto it = s.lower_bound(a);
		if (it != s.begin())
			s.erase(--it);
		
		s.insert(a);
	}

	cout << s.size() << endl;
}

//// done E in 10min on 28, Sep, 2019 ////
