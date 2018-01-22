#include <iostream>
#include <algorithm>

using namespace std;

struct Activity
{
	int s, f;
};

int mycmp(Activity& a, Activity& b)
{
	return a.f < b.f;
}

int main()
{
	int n;
	cin >> n;

	Activity* a = new Activity[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].s >> a[i].f;
	}
	sort(a, a + n, mycmp);

	int last = 0;

	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (last <= a[i].s)
		{
			cout << '[' << a[i].s << ',' << a[i].f << ']';
			last = a[i].f;
			m++;
		}
	}
	cout << endl << "Possible Maximum Number of Activity : " << m << endl;
	
	delete[] a;
	return 0;
}