

#include "BST.h"
#include <cstdio>

int main()
{
	BST<char> T;

	while (1)
	{
		int op;
		char key;
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			getchar();
			scanf("%c", &key);
			T.insertion(key);
			break;
		case 2:
			getchar();
			scanf("%c", &key);
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