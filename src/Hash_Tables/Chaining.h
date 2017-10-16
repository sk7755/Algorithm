//	Hash Table using chaining method
//	CLRS 11.2 Hash tables
//	Written by Jeong Jae Hoon 2017-10-17

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
	
	//	Constructor of Hash Table
	//	Input:	size of hash table, hash function
	//	Time:	O(n)
	Chaining(int n, int(*hash)(int, int));

	//	Insert key in hash table
	//	Input:	key
	//	Time:	O(1+a) expected time under simple uniform hashing (a is load factor a = n/m) 
	void insertion(int key);

	//	Search key in hash table
	//	Input:	key
	//	Output:	slot address which has key. if not exist, return nullptr
	//	Time:	O(1+a) expected time under simple uniform hashing
	nptr search(int key);

	//	Delete key in hash table
	//	Input:	address which have key
	//	Time:	O(1)
	void deletion(nptr p);

	//	Print all keys in hash table
	//	Time:	O(n)
	void print();

	//	Destructor of hash table
	//	Time:	O(n)
	~Chaining();
};

#endif