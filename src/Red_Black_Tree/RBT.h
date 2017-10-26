#ifndef __RBT_H__
#define __RBT_H__

enum COLOR{ RED,BLACK };

//if you inheritate NODE in BST, refer to https://stackoverflow.com/questions/27601537/java-self-reference-with-inhertiance
//The reason I don't use inheritance is that I want this header file activate one complete unit.
typedef struct NODE* nptr;

struct NODE
{
	int key;
	nptr left, right;
	nptr parent;
	COLOR color;
};

class RBT
{
private:
	nptr root;
	int n;
	nptr sentinel;
public:
	RBT();
	void insertion(int key);
	void insert_fixup(nptr x);
	nptr search(int key);
	void deletion(nptr x);
	void delete_fixup(nptr x);
	int black_height(nptr x);
	int isempty();
	int size();
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
	~RBT();
};

#endif