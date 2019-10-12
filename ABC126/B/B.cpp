#include <iostream>
#include <set>

using namespace std;

set<int> mths{ 1,2,3,4,5,6,7,8,9,10, 11, 12 };

int main()
{
	int a, b, x;
	cin >> x;
	a = x / 100;
	b = x % 100;

	int m_a = mths.count(a);
	int m_b = mths.count(b);


	if (m_a && m_b)
	{
		cout << "AMBIGUOUS" << endl;
		return 0;
	}

	if (m_a)
	{
		cout << "MMYY" << endl;
		return 0;
	}

	if (m_b)
	{
		cout << "YYMM" << endl;
		return 0;
	}

	cout << "NA" << endl;
}
