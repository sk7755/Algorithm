#ifndef __BST_H__
#define __BST_H__

template <class T>
struct NODE
{
	T key;
	NODE *left, *right;
	NODE *parent;
};

template <class T>
class BST
{
private:
	using nptr = NODE<T>*;
	nptr root;
	int n;
public:
	BST();
	BST(T a[], int n);
	int isempty();
	int size();
	void insertion(T key);
	nptr search(T key);
	void deletion(nptr x);
	void transparent(nptr u, nptr v);
	void left_rotation(nptr x);
	void right_rotation(nptr x);
	nptr min(nptr x);
	nptr max(nptr x);
	nptr successor(nptr x);
	nptr predecessor(nptr x);
	void print_tree(nptr x);
	void print();
	void nonrecursive_print();
	void cleaner(nptr x);
	~BST();
};
#include "BST.cpp"
#endif