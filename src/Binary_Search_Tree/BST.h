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
protected:
	nptr root;
	int n;
public:
	BST();
	int isempty();
	int size();
	void insertion(int key);
	nptr search(int key);
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

#endif