#include "Interval_RBtree.h"
#include <iostream>

using namespace std;
using namespace INTERVAL_RBTREE;

int main()
{
	try {
		Interval_RBtree T;

		while (1)
		{
			int op;
			interval i;
			cin >> op;
			switch (op)
			{
			case 1:
				cin >> i;
				T.insertion(i);
				break;
			case 2:
				cin >> i;
				T.deletion(T.search(i));
				break;
			case 3:
				T.print();
				T.nonrecursive_print();
				break;
			}
		}
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
	}
}