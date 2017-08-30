#include "Stack.h"
#include "Queue.h"

int main()
{
	int size;
	scanf("%d", &size);
	Queue queue(size);
	while (1)
	{
		int op;
		scanf("%d", &op);

		if (op == 1)
		{
			int key;
			scanf("%d", &key);
			queue.push(key);
		}
		else if (op == 2)
		{
			printf("%d\n", queue.top());
			queue.pop();
		}
	}

}