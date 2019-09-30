#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

#define PB push_back
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef vector<int> Vi;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
inline void YES() { cout << "YES" << endl; } inline void Yes() { cout << "Yes" << endl; }
inline void NO() { cout << "NO" << endl; } inline void No() { cout << "No" << endl; }


int n, founder = 0;
Vi slimes;
multiset<int> duty;

void init()
{
	cin >> n;

	REP(_i, (1 << n))
	{
		int s; cin >> s;
		duty.insert(s);
		chmax(founder, s);
	}
}

int main()
{
	init();

	slimes.PB(founder);
	duty.erase(duty.find(founder));

	REP(i, n)
	{
		Vi newgen(slimes);
		for (int par : slimes)
		{
			auto it = duty.lower_bound(par);
			if (it == duty.begin())
			{
				// cout << "trying to produce " << *it << " from parent " << slimes[par] << endl;
				No(); return 0;
			}

			newgen.PB(*(--it));
			duty.erase(it);
		}
		sort(ALL(newgen), greater<>());
		swap(slimes, newgen);
	}

	Yes();

}
