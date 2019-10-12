#include <iostream>
#include <set>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }

set <int> s;

int main()
{
	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;
	s.insert(a);
	s.insert(b);

	int k;
	cin >> k;

	REP(_i, k)
	{
		int c;
		cin >> c;

		s.insert(c);
	}

	if (s.size() == 2 + k)
		YES();
	else
		NO();
}
