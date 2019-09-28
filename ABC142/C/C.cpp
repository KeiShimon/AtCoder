#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef pair<int, int> pii;


int main()
{
	int n;
	vector<pii> s;

	cin >> n;
	REP(i, n)
	{
		int a; cin >> a;
		s.PB(pii(a, i + 1));
	}

	sort(ALL(s));

	REP(i, n)
		cout << s[i].second << " ";
	cout << endl;

}
