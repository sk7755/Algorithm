//#include "Stack.h"
//#include "Queue.h"
//#include "Linked_List.h"
#include "Rooted_Tree.h"

int main()
{
	Rooted_Tree T;
	while (1)
	{
		int op;
		int key;
		scanf("%d", &op);

		if (op == 1)
		{
			scanf("%d", &key);
			T.push(key);
		}
		else if (op == 2)
		{

			scanf("%d", &key);
			nptr p = T.search(key);
			if (p)
				printf("Success %d\n", p->key);
			else
				printf("Fail\n");
		}
		else if (op == 3)
		{
			T.print_all();
		}
		else if (op == 4)
			return 0;
	}

}