#ifndef __AVLtree_CPP__
#define __AVLtree_CPP__

#include "AVLtree.h"
#include <iostream>

using namespace std;

AVLtree::AVLtree() :n(0)
{
	sentinel = new NODE;
	sentinel->left = sentinel->right= sentinel->parent = sentinel;
	sentinel->height = 0;
	root = sentinel;
}
void AVLtree::insertion(int key)
{
	nptr pnew = new NODE;
	pnew->key = key;
	pnew->left = pnew->right = sentinel;
	pnew->height = 0;

	nptr x = root;
	nptr y = sentinel;

	while (x != sentinel)
	{

		y = x;
		if (x->key < key)
			x = x->right;
		else
			x = x->left;
	}
	pnew->parent = y;

	if (y == sentinel)
		root = pnew;
	else if (y->key < key)
		y->right = pnew;
	else
		y->left = pnew;
	n++;

	balance(pnew);
	
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

void AVLtree::balance(nptr x)
{
	while (x != sentinel)
	{
		x->height = max(x->left->height, x->right->height) + 1;

		if (x->left->height > x->right->height + 1)
		{
			if (x->left != sentinel && x->left->left->height < x->left->right->height)
				left_rotation(x->left);
			right_rotation(x);
			x = x->parent;
		}
		else if (x->right != sentinel && x->right->height < x->left->height + 1)
		{
			if (x->right->right->height < x->right->left->height)
				right_rotation(x->right);
			left_rotation(x);
			x = x->parent;
		}
		x = x->parent;
	}
}

AVLtree::nptr AVLtree::search(int key)
{
	nptr x = root;
	while (x != sentinel)
	{
		if (x->key < key)
			x = x->right;
		else if (x->key > key)
			x = x->left;
		else
			return x;
	}

	return x;
}
void AVLtree::deletion(nptr x);
int AVLtree::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}
int AVLtree::size()
{
	return n;
}
int AVLtree::max()
{
	return max_subtree(root)->key;
}
int AVLtree::min()
{
	return min_subtree(root)->key;
}

AVLtree::nptr AVLtree::successor(nptr x);
AVLtree::nptr AVLtree::predecessor(nptr x);
void AVLtree::print();
~AVLtree();

#endif