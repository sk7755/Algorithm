//	Hash Table using chaining method
//	CLRS 11.2 Hash tables
//	Written by Jeong Jae Hoon 2017-10-17

#ifndef __CHAINING_H__
#define __CHAINING_H__

template <class T>
struct NODE
{
	T key;
	NODE* next;
	NODE* pre;
};

template <class T>
class Chaining
{
private:
	using nptr = NODE<T>*;

	int n;
	nptr *data;
	nptr *sentinel;
	int(*hash) (T, int);
public:
	
	//	Constructor of Hash Table
	//	Input:	size of hash table, hash function
	//	Time:	O(n)
	Chaining(int n, int(*hash)(T, int));

	//	Insert key in hash table
	//	Input:	key
	//	Time:	O(1+a) expected time under simple uniform hashing (a is load factor a = n/m) 
	void insertion(T key);

	//	Search key in hash table
	//	Input:	key
	//	Output:	slot address which has key. if not exist, return nullptr
	//	Time:	O(1+a) expected time under simple uniform hashing
	NODE<T>* search(T key);

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

#include "Chaining.cpp"
#endif