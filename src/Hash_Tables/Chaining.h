#ifndef __CHAINING_H__
#define __CHAINING_H__

#include <cstdio>

enum{ sentinel = -2000000000};

typedef struct NODE* nptr;

struct NODE
{
	int key;
	nptr next;
	nptr pre;
};

class Chaining
{
private:
	int n;
	nptr *data;
	int(*hash) (int, int);
public:
	Chaining(int n, int(*hash)(int, int));
	void insertion(int key);
	nptr search(int key);
	void deletion(nptr p);
	void print();
	~Chaining();
};

#endif