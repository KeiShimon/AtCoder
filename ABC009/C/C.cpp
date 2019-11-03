#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i,x) for(int i{ 0 }; i < (int)(x); i++)
#define REPC(i,x) for(int i{ 0 }; i <= (int)(x); i++)

typedef vector<int> Vi;

int N, K;
char s[101], t[101];

int main()
{
	cin >> N >> K;
	cin >> s;

	Vi due(26, 0);
	REP(i, N) due[s[i] - 'a']++;

	REP(i, N)
	{
		for (char c = 'a'; c <= 'z'; ++c)
			if (due[c - 'a'])
			{
				t[i] = c;
				due[c - 'a']--;

				int n_mismatch = 0;
				REPC(j, i)
					n_mismatch += s[j] != t[j];

				Vi cnt_later(26, 0);
				for (int j = i + 1; j < N; ++j)
					cnt_later[s[j] - 'a']++;

				int n_mismatch_later = 0;
				REP(j, 26)
					n_mismatch_later += abs(cnt_later[j] - due[j]);
				n_mismatch += n_mismatch_later / 2;

				// ok!!
				if (n_mismatch <= K)
					break;

				// ng!! -> revert
				due[c - 'a']++;
				t[i] = '?';
			}
	}

	cout << t << endl;
}
