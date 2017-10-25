#include "BST.h"
#include <cstdio>
#include "Random_BST.h"

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	Random_BST T(a,10);
	T.print();

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