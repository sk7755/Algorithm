#ifndef __BST_H__
#define __BST_H__

typedef struct NODE* nptr;

struct NODE
{
	int key;
	nptr left, right;
	nptr parent;
};

class BST
{
private:
	nptr root;
	int n;
public:
	BST();
	int isempty();
	int size();
	void insertion(int key);
	nptr search(int key);
	void transparent(nptr u, nptr v);
	nptr min(nptr x);
	nptr max(nptr x);
	nptr successor(nptr x);
	nptr predecessor(nptr x);
	void deletion(nptr x);
	void print_tree(nptr x);
	void print();
	void nonrecursive_print();
	void cleaner(nptr x);
	~BST();
};

#endif