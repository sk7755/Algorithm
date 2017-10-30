#ifndef __RBtree_H__
#define __RBtree_H__

//if you inheritate NODE in BST, refer to https://stackoverflow.com/questions/27601537/java-self-reference-with-inhertiance
//The reason I don't use inheritance is that I want this header file activate one complete unit.

class RBtree
{
public:
	enum COLOR { RED, BLACK };

	struct NODE
	{
		int key;
		NODE *left, *right, *parent;
		COLOR color;
	};

	using nptr = NODE*;
private:
	nptr root;
	int n;
	nptr sentinel;

	void insert_fixup(nptr x);
	void delete_fixup(nptr x);
	void transparent(nptr u, nptr v);
	void left_rotation(nptr x);
	void right_rotation(nptr x);
	nptr min_subtree(nptr x);
	nptr max_subtree(nptr x);
	void print_tree(nptr x);
	void cleaner(nptr x);

public:
	RBtree();
	void insertion(int key);
	nptr search(int key);
	void deletion(nptr x);
	int black_height(nptr x);
	int isempty();
	int size();
	int max();
	int min();
	nptr successor(nptr x);
	nptr predecessor(nptr x);
	void print();
	void nonrecursive_print();
	~RBtree();
};

#endif