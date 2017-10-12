#include <cstdio>
#include <cstdlib>
#include "Chaining.h"
#include "Open_Addressing.h"
#include "Hash_Function.h"

int main()
{
	int n;
	scanf("%d", &n);

	Chaining* chain = new Chaining(n, division_hash);
	Open_Addressing* open_address = new Open_Addressing(n, double_hash);
	
	
	while (1)
	{
		int op;
		int key;
		scanf("%d", &op);

		switch (op)
		{
		case 1:
			scanf("%d", &key);
			open_address->insertion(key);
			break;
		case 2:
			scanf("%d", &key);
			open_address->deletion(open_address->search(key));
			break;
		case 3:
			open_address->print();
			break;
		case 4:
			delete open_address;
			return 0;
		}

	}
}