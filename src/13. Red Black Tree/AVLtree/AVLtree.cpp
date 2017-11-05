#ifndef __AVLtree_CPP__
#define __AVLtree_CPP__

#include "AVLtree.h"
#include <iostream>

using namespace std;
using namespace AVLTREE;

template <class T>
AVLtree<T>::AVLtree() :n(0)
{
	sentinel = new NODE<T>;
	sentinel->left = sentinel->right= sentinel->parent = sentinel;
	sentinel->height = 0;
	root = sentinel;
}

template <class T>
void AVLtree<T>::insertion(T key)
{
	nptr pnew = new NODE<T>;
	pnew->key = key;
	pnew->left = pnew->right = sentinel;
	pnew->height = 1;

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

template <class T>
void AVLtree<T>::balance(nptr x)
{
	while (x != sentinel)
	{
		x->height = max(x->left->height, x->right->height) + 1;

		if (x->left->height > x->right->height + 1)
		{
			if (x->left->left->height < x->left->right->height)
				left_rotation(x->left);
			right_rotation(x);
			x = x->parent;
		}
		else if (x->right->height > x->left->height + 1)
		{
			if (x->right->right->height < x->right->left->height)
				right_rotation(x->right);
			left_rotation(x);
			x = x->parent;
		}


		x = x->parent;
	}
}

template <class T>
NODE<T>* AVLtree<T>::search(T key)
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

template <class T>
void AVLtree<T>::deletion(nptr x)
{
	if (x == sentinel)
		return;

	nptr z;
	if (x->left == sentinel)
	{
		z = x->right;
		transparent(x, x->right);
	}
	else if (x->right == sentinel)
	{
		z = x->left;
		transparent(x, x->left);
	}
	else
	{
		nptr y = min_subtree(x->right);
		z = y->right;
		if (y->parent != x)
		{
			transparent(y, y->right);
			y->right = x->right;
			x->right->parent = y;
		}
		transparent(x, y);
		y->left = x->left;
		x->left->parent = y;
	}

	delete x;
	n--;

	balance(z);
}

template <class T>
int AVLtree<T>::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}

template <class T>
int AVLtree<T>::size()
{
	return n;
}


template <class T>
T AVLtree<T>::max()
{
	return max_subtree(root)->key;
}

template <class T>
T AVLtree<T>::min()
{
	return min_subtree(root)->key;
}

template <class T>
NODE<T>* AVLtree<T>::successor(nptr x)
{
	if (x->right)
		return min_subtree(x->right);

	while (x != root && x->parent->right == x)
		x = x->parent;

	return x->parent;
}

template <class T>
NODE<T>* AVLtree<T>::predecessor(nptr x)
{
	if (x->left)
		return max_subtree(x->left);

	while (x != root && x->parent->left == x)
		x = x->parent;

	return x->parent;
}

template <class T>
void AVLtree<T>::print()
{
	nptr x = root;
	int pre = 0; //0 = parent, 1 = left child, 2 = right child 

	if (x == sentinel)
		return;

	while (1)
	{
		if (pre == 0)
		{
			if (x->left != sentinel)
				x = x->left;
			else
				pre = 1;
		}
		if (pre == 1)
		{
			cout << x->key << ' ';
			if (x->right != sentinel)
			{
				pre = 0;
				x = x->right;
			}
			else
				pre = 2;
		}
		if (pre == 2)
		{
			if (x->parent == sentinel)
				break;

			if (x->parent->left == x)
				pre = 1;
			else
				pre = 2;
			x = x->parent;
		}
	}
	cout << endl;
}

template <class T>
NODE<T>* AVLtree<T>::min_subtree(nptr x)
{
	if (x != sentinel)
	{
		while (x->left != sentinel)
			x = x->left;
	}
	return x;
}

template <class T>
NODE<T>* AVLtree<T>::max_subtree(nptr x)
{
	if (x != sentinel)
	{
		while (x->right != sentinel)
			x = x->right;
	}
	return x;
}

template <class T>
void AVLtree<T>::transparent(nptr u, nptr v)
{
	if (u == root)
		root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;

	v->parent = u->parent;
}

template <class T>
void AVLtree<T>::left_rotation(nptr x)
{
	nptr y = x->right;	//assume that x,y is not nullptr
	x->right = y->left;
	if (y->left != sentinel)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == sentinel)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;

	x->height = max(x->left->height, x->right->height) + 1;
	y->height = max(y->left->height, y->right->height) + 1;
}

template <class T>
void AVLtree<T>::right_rotation(nptr x)
{
	nptr y = x->left;	//assume that x,y is not nullptr
	x->left = y->right;
	if (y->right != sentinel)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == sentinel)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->right = x;
	x->parent = y;

	x->height = max(x->left->height, x->right->height) + 1;
	y->height = max(y->left->height, y->right->height) + 1;
}


template <class T>
int AVLtree<T>::height()
{
	return root->height;
}


template <class T>
void AVLtree<T>::destruct_subtree(nptr x)
{
	if (x == sentinel)
		return;
	destruct_subtree(x->left);
	destruct_subtree(x->right);
	delete x;
}


template <class T>
AVLtree<T>::~AVLtree()
{
	destruct_subtree(root);
	delete sentinel;
}

#endif