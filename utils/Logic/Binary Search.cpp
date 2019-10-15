using namespace std;

bool check();

int ng, ok;

while (abs(ng - ok) > 1)
{
	auto mid = (ng + ok) / 2;

	if (check(mid))
		ok = mid;
	else
		ng = mid;
}

//if (ok == t)
//	cout << "for all x, f(x) = false" << endl;
//else
//	cout << ok << endl;