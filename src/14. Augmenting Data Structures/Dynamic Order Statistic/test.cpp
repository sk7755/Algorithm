#include "OS_RBtree.h"
#include <iostream>

using namespace std;
using namespace OS_RBTREE;

int main()
{
	try {
		OS_RBtree<int> T;

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
				break;
			case 4:
				cin >> key;
				cout << T.successor(T.search(key))->key << ' ' << T.predecessor(T.search(key))->key << endl;
				break;
			case 5:
				cout << T.min() << ' ' << T.max() << endl;
				break;
			case 6:
				int rank;
				cin >> rank;
				int key = T.select(rank);
				cout << key << ' ' <<T.rank(T.search(key))<< endl;
				break;
			}
		}
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
	}
}