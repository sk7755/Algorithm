#include "BStree.h"
#include <iostream>

using namespace std;

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	BStree<int> T(a,10);

	while (1)
	{
		int op;
		int key;
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> key;
			T.insertion(key);
			break;
		case 2:
			cin >> key;
			T.deletion(T.search(key));
			break;
		case 3:
			T.print();
			T.nonrecursive_print();
			cout << T.min() << ' ' << T.max() << endl;
			break;
		case 4:
			return 0;
		}
	}
}