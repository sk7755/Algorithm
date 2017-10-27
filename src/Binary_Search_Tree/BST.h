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

	nptr min_subtree(nptr x);
	nptr max_subtree(nptr x);
	void knuth_shuffle(T a[], int n);
	void init_seed();
	int uniform(int a, int b);
	void transparent(nptr u, nptr v);
	void cleaner(nptr x);
	void print_tree(nptr x);
public:
	BST();
	BST(T a[], int n);
	int isempty();
	int size();
	void insertion(T key);
	nptr search(T key);
	void deletion(nptr x);
	nptr successor(nptr x);
	nptr predecessor(nptr x);
	T min();
	T max();
	void print();
	void nonrecursive_print();
	~BST();
};
#include "BST.cpp"
#endif