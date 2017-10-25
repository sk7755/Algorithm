#ifndef __RBT_H__
#define __RBT_H__

#include "../Binary_Search_Tree/BST.h"

typedef struct RB_NODE* rbnptr;
enum COLOR{ RED,BLACK };

struct RB_NODE : public NODE
{
	COLOR color;
};

class RBT : public BST
{
protected:
	rbnptr sentinel;
public:
	RBT();
	void insertion(int key);
	void insert_fixup(rbnptr x);
	rbnptr search(int key);
	void deletion(rbnptr x);
	void delete_fixup(rbnptr x);
	int black_height(rbnptr x);
	~RBT();
};

#endif