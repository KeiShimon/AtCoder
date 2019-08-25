#include <iostream>

using namespace std;

class B {
	int N, ans{ 0 };
	string S;
public:
	void solve()
	{
		cin >> N >> S;
		int tmpCount{ 0 };
		int leftMask{ 0 }, rightMask{ 0 };
		int i{ 0 };

		for (int sep{ 1 }; sep < N; sep++)
		{
			leftMask = rightMask = tmpCount = 0;
			
			for (i = 0; i < sep; i++)
				leftMask |= (1 << (S[i] - 'a'));
			for (; i < N; i++)
				rightMask |= (1 << (S[i] - 'a'));
			
			for (i = 0; i < 26; i++)
			{
				if ((leftMask & (1 << i)) & (rightMask & (1 << i))) tmpCount++;
			}

			if (ans < tmpCount) ans = tmpCount;
			
		}
		cout << ans << endl;
	}
};


int main()
{
	B solution;
	solution.solve();

	return 0;
}