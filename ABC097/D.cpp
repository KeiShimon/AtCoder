#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

#include <unordered_map>
#include <unordered_set>

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)
#define RREP(i,x) for(int i{ (int)(x) - 1 }; i >= 0 ;i--)
#define RREPC(i,x) for(int i{ (int)(x)}; i >= 0; i--)
#define REP1O(i,x) for(int i{ 1 }; i < (int)(x); i++)
#define REP1C(i,x) for(int i{ 1 }; i <= (int)(x); i++)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

typedef int64_t ll;

const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INTMAX = 2147483647;
const ll LLMAX = 9223372036854775807;

template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

using namespace std;

template<class T> void SWAP(T& a, T& b) { a ^= b; b ^= a; a ^= b; }

class D {
	int n, m;
	vector<int> p;
	unordered_map<int, unordered_set<int>> unions;
	vector<int> parent;

public:
	D()
	{
		cin >> n >> m;
		p.resize(n);

		int tmp;
		REP(i, n)
		{
			cin >> tmp;
			p[i] = tmp - 1;
		}
		parent.resize(n, -1);

		int a, b;
		REP(i, m)
		{
			cin >> a >> b;
			add(a - 1, b - 1);
		}
	}

	int root(int a)
	{
		if (parent[a] < 0)
			return a;

		parent[a] = root(parent[a]);
		return parent[a];

	}

	void add(int a, int b)
	{
		int a_root{ root(a) };
		int b_root{ root(b) };

		if (a_root == b_root)
			return;

		int size_a{ parent[a_root] };
		int size_b{ parent[b_root] };

		if (size_a > size_b)
		{
			SWAP(a_root, b_root);
			SWAP(size_a, size_b);
		}

		parent[b_root] = a_root;
		parent[a_root] += size_b;

	}

	void solve()
	{
		int ans{ 0 };

		REP(i, n)
		{
			if (parent[i] == -1)
			{
				if (p[i] == i)
					++ans;
			}
			else if (parent[i] < 0)
			{
				if (unions.find(i) == unions.end())
				{
					unordered_set<int> tmp{ i };
					unions.emplace(MP(i, tmp));
				}
			}
			else
			{
				int rt{ root(i) };
				auto un{ unions.find(rt) };
				if (un == unions.end())
				{
					unordered_set<int> tmp{ i, rt };
					unions.emplace(MP(rt, tmp));
				}
				else
					un->second.insert(i);
			}
		}

		for (auto un{ unions.begin() }; un != unions.end(); un++)
		{
			for (int i : un->second)
			{
				if (un->second.count(p[i]))
					++ans;
			}
		}

		cout << ans << endl;
	}

	void debug()
	{
		cout << "=========== debug FROM HERE =============" << endl << endl;

		for (auto un{ unions.begin() }; un != unions.end(); un++)
		{
			cout << "key = " << un->first << "  val(set) : { ";

			for (int x : un->second)
				cout << x << " ";
			cout << "}" << endl;

		}
		cout << endl;

		//cout << "printing vector parent..." << endl;
		//REP(i, n)
		//	cout << parent[i] << " ";

		cout << endl << "=========== debug END =============" << endl << endl;

	}

};

int main()
{
	D solution;
	solution.solve();

	return 0;
}