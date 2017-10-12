#ifndef __OPEN_ADDRESSING_H__
#define __OPEN_ADDRESSING_H__

#include <cstdio>

enum {
	DELETED = -2000000000,
	EMPTY = -1999999999
};

class Open_Addressing
{
private:
	int n;
	int* data;
	int(*hash)(int, int, int);
public:
	Open_Addressing(int n, int(*hash)(int, int, int));
	int insertion(int key);
	int search(int key);
	void deletion(int slot);
	void print();
	~Open_Addressing();
};

#endif