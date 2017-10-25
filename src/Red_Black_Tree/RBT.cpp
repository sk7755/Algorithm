#include "RBT.h"

RBT::RBT() : BST()
{
	sentinel = new RB_NODE;
	sentinel->color = BLACK;
	root = sentinel;
}

void RBT::insertion(int key)
{
	rbnptr pnew = new RB_NODE;
	pnew->key = key;
	pnew->left = pnew->right = nullptr;

	nptr x = root;
	nptr y = sentinel;
	while (x)
	{
		y = x;
		if (x->key < key)
			x = x->right;
		else
			x = x->left;
	}
	pnew->parent = y;
	if (y == sentinel)
	{
		root = pnew;
		return;
	}

	if (y->key < key)
		y->right = pnew;
	else
		y->left = pnew;
	n++;
	pnew->color = RED;
	insert_fixup(pnew);
}

void RBT::insert_fixup(rbnptr x)
{
	while (((rbnptr)(x->parent))->color == RED)
	{

	}
}
rbnptr RBT::search(int key);
void RBT::deletion(rbnptr x);
void RBT::delete_fixup(rbnptr x);
int RBT::black_height(rbnptr x);
RBT::~RBT();