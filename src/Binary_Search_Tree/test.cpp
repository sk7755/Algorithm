#include "BST.h"
#include <cstdio>

int main()
{
	BST T;

	while (1)
	{
		int op;
		int key;
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			scanf("%d", &key);
			T.insertion(key);
			break;
		case 2:
			scanf("%d", &key);
			T.deletion(T.search(key));
			break;
		case 3:
			T.print();
			T.nonrecursive_print();
			break;
		case 4:
			return 0;
		}
	}
}