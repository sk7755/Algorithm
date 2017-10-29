#ifndef __AVLTREE_H__
#define __AVLTREE_H__

class AVLtree
{
public:
	struct NODE
	{
		int key;
		NODE *left, *right, *parent;
		int height;
	};
	using nptr = NODE*;
private:
	nptr root;
	int n;

	void balance(nptr x);
	nptr min_subtree();
	nptr max_subtree();
	void transparent(nptr u, nptr v);
	void left_rotation(nptr x);
	void right_rotation(nptr x);
	void destruct_subtree(nptr x);
public:
	AVLtree();
	void insertion(int key);
	nptr search();
	void deletion(nptr x);
	int isempty();
	int size;
	int max();
	int min();
	nptr successor(nptr x);
	nptr predecessor(nptr x);
	void print();
	~AVLtree();
};

#endif