#include <iostream>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)

inline void swap(int& a, int& b) { a ^= b; b ^= a; a ^= b; }

int N;
int v[]{ 1,2,3,4,5,6 };

int main()
{
	cin >> N;
	N %= 30;

	REP(i, N)
		swap(v[i % 5], v[i % 5 + 1]);

	REP(i, 6) cout << v[i];
	cout << endl;
}
