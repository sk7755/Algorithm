//	Hash Table using Open addressing which have integer data
//	CLRS 11.4 Open addressing
//	Written by Jeong Jae Hoon 2017-10-17

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

	//	Constructor of hash table
	//	Input:	1. size of hash table
	//			2. hash function which inputs are key, i th , size of hash table and output is slot index
	//	Time:	O(n)
	Open_Addressing(int n, int(*hash)(int, int, int));

	//	Insert key to hash table
	//	Input:	1. key
	//	Output:	1. slot number which key go to
	//	Time:	average O(1/(1-a)) (a is load factor a = n/m < 1)
	int insertion(int key);

	//	Search key in hash table
	//	Input:	1. key
	//	Output:	1. slot number where key exist. if there not exist, return NULL pointer
	//	Time:	Unsuccessful search average O(1/(1-a))
	//			Successful search average  O( (1/a) * ln(1/(1-a)) )
	int search(int key);

	//	Delete key in hash table
	//	Input:	1. slot number
	//	Time:	O(1)
	void deletion(int slot);

	//	Print all keys in hash table
	//	Time:	O(n)
	void print();

	//	Destructor of hash table
	//	Time O(n)
	~Open_Addressing();
};

#endif