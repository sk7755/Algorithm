//10.4 Representing rooted trees (p 246)
//I want to add special condition while coding this.
//left subtree are smaller than elements in right subtrees
//the number of child can be larger than binary(2) such that left child, right sibiling
//So print function print elements non-decreasing order
//Written by Jeong Jae Hoon 2017-09-15

#ifndef __ROOTED_TREE_H__
#define __ROOTED_TREE_H__

#include <cstdio>

typedef struct NODE* nptr;

struct NODE
{
	int key;
	nptr left, right;	//left child, right sibiling
};

class Rooted_Tree
{
private:
	nptr root;
public:
	//Constructor of Rooted Tree
	Rooted_Tree();

	//push key in Rooted tree such that elements in left subtree are smaller than elements in right subtrees 
	//the number of child can be the integer larger than 2
	//Input		:	key which want to push
	//Time		:	O(log n) expected time
	void push(int key);
	
	//search node pointer whose key is Input
	//Input		:	key which element have
	//Output	:	element pointer whose key is input
	//Time		:	O(long n) expected time
	nptr search(int key);

	//print all elements
	//Time		:	O(n)
	void print_all();
	void print(nptr x);

	//Destructor of Rooted Tree
	~Rooted_Tree();
	void delete_line(nptr x);

};

#endif