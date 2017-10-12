#include "Open_Addressing.h"

Open_Addressing::Open_Addressing(int n, int(*hash)(int, int, int)) : n(n), hash(hash)
{
	data = new int[n];
	for (int i = 0; i < n; i++)
		data[i] = EMPTY;
}
int Open_Addressing::insertion(int key)
{
	for (int i = 0; i < n; i++)
	{
		int x = hash(key, i, n);
		if (data[x] == EMPTY || data[x] == DELETED)
		{
			data[x] = key;
			return x;
		}
	}
}
int Open_Addressing::search(int key)
{
	for (int i = 0; i < n; i++)
	{
		int x = hash(key, i, n);
		if (data[x] == key)
			return x;
		if (data[x] == EMPTY)
			return -1;	//not exist
	}
	return -1;	//full
}
void Open_Addressing::deletion(int slot)
{
	data[slot] = DELETED;
}

void Open_Addressing::print()
{
	for (int i = 0; i < n; i++)
		printf("%d ", data[i]);
	printf("\n");
}
Open_Addressing::~Open_Addressing()
{
	delete[]data;
}