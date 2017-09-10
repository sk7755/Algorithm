#include "Stack.h"
#include "Queue.h"
#include "Linked_List.h"

int main()
{
	Linked_List L;
	while (1)
	{
		int op;
		int key;
		scanf("%d", &op);

		if (op == 1)
		{
			scanf("%d", &key);
			L.push(key);
		}
		else if (op == 2)
		{
			
			scanf("%d", &key);
			L.pop(L.search(key));
		}
		else if (op == 3)
		{
			L.print();
		}
	}

}