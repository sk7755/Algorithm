#ifndef __AVLtree_CPP__
#define __AVLtree_CPP__

#include "AVLtree.h"
#include <iostream>

using namespace std;

AVLtree::AVLtree() :n(0)
{
	root = nullptr;
}
void AVLtree::insertion(int key)
{
	nptr pnew = new NODE;
	pnew->key = key;
	pnew->left = pnew->right = nullptr;
	pnew->height = 0;

	nptr x = root;
	nptr y = nullptr;

	while (x)
	{

		y = x;
		if (x->key < key)
			x = x->right;
		else
			x = x->left;
	}
	pnew->parent = y;

	if (y == nullptr)
		root = pnew;
	else if (y->key < key)
		y->right = pnew;
	else
		y->left = pnew;
	n++;

	balance(pnew);
	
}
AVLtree::nptr AVLtree::search();
void AVLtree::deletion(nptr x);
int AVLtree::isempty();
int AVLtree::size;
int AVLtree::max();
int AVLtree::min();
AVLtree::nptr AVLtree::successor(nptr x);
AVLtree::nptr AVLtree::predecessor(nptr x);
void AVLtree::print();
~AVLtree();

#endif