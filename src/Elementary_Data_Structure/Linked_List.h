//	Linked List Class which have integer key
//	CLRS 10.2 Linked List (p236)
//	Written by Jeong Jae Hoon 2017-09-10

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <cstdio>

typedef struct NODE* nptr;

struct NODE
{
	int key;
	nptr next, pre;
};


class Linked_List
{
private:
	nptr sentinel;
public:

	//	Constructor of Linked List
	Linked_List();

	//	Push key in Linked List
	//	Input	:	key
	//	Time	:	O(1)
	void push(int key);

	//	Pop element whose address is x
	//	Input	:	address to pop
	//	Time	:	O(1)	
	void pop(nptr x);

	//	Search the element whose key is same to input
	//	Input	:	key to search
	//	Output	:	if key is in linked list, output is address to find
	//				if not, output is nullptr
	//	Time	:	O(n) Worstcase (n is length of linked list)
	nptr search(int key);

	//	Print elements in linked list
	//	Time	:	O(n) Totalcase (n is length of linked list)
	void print();

	//	Destructor of Linked List
	~Linked_List();

};

#endif