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
	nptr sentinel;
	int n;

	void balance(nptr x);
	inline int max(int a, int b);
	nptr min_subtree(nptr x);
	nptr max_subtree(nptr x);
	void transparent(nptr u, nptr v);
	void left_rotation(nptr x);
	void right_rotation(nptr x);
	void destruct_subtree(nptr x);
public:
	AVLtree();
	void insertion(int key);
	nptr search(int key);
	void deletion(nptr x);
	int isempty();
	int size();
	int max();
	int min();
	nptr successor(nptr x);
	nptr predecessor(nptr x);
	void print();
	~AVLtree();
};

#endif