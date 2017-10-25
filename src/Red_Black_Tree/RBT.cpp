#include "RBT.h"

RBT::RBT() :n(0)
{
	sentinel = new NODE;
	sentinel->color = BLACK;
	root = sentinel;
}

void RBT::insertion(int key)
{
	nptr pnew = new NODE;
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

void RBT::insert_fixup(nptr x)
{
	while (x->parent->color == RED)
	{
		;
	}
}