using namespace std;

bool check();
int s, t;


int ng = s - 1, ok = t;
while (ng - ok > 1)
{
	int mid = (ng + ok) / 2;
	(check(mid) ? ok : ng) = mid;
}

if (ok == t)
	cout << "for all x, f(x) = false" << endl;
else
	cout << ok << endl;