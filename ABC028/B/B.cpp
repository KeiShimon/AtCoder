#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	int cnt[6];
	memset(cnt, 0, sizeof cnt);

	string s; cin >> s;
	for (char c : s)
		cnt[c - 'A']++;

	for (int i = 0; i < 5; ++i)
		cout << cnt[i] << " ";
	cout <<cnt[5] << endl;
}
