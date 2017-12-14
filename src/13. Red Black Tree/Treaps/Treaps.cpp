#ifndef __Treaps_CPP__
#define __Treaps_CPP__

#include "Treaps.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace TREAPS;

template <class T>
Treaps<T>::Treaps() :n(0)
{
	sentinel = new NODE<T>;
	sentinel->left = sentinel->right = sentinel;
	sentinel->priority = MAX_PRIORITY;
	root = sentinel;
	srand(time(NULL));
}

template <class T>
void Treaps<T>::insertion(T key)
{
	nptr pnew = new NODE<T>;
	pnew->key = key;
	pnew->left = pnew->right = sentinel;
	pnew->priority = rand();

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
	
	insert_fixup(pnew);
}

template <class T>
void Treaps<T>::insert_fixup(nptr x)
{
	while (x != root && x->parent->priority > x->priority)
	{
		if (x->parent->left == x)
			right_rotation(x->parent);
		else
			left_rotation(x->parent);

	}
}

template <class T>
void Treaps<T>::deletion(nptr x)
{
	if (x == sentinel)
		return;

	while (x->left != sentinel || x->right != sentinel)
	{
		nptr smallest;
		if (x->left->priority < x->right->priority)
			right_rotation(x);
		else
			left_rotation(x);
	}

	if (x->parent == sentinel)
		root = sentinel;
	else if (x->parent->key < x->key)
		x->parent->right = sentinel;
	else
		x->parent->left = sentinel;
	
	delete x;
	n--;
}

template <class T>
NODE<T>* Treaps<T>::search(T key)
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

	return sentinel;
}

template <class T>
int Treaps<T>::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}

template <class T>
int Treaps<T>::size()
{
	return n;
}

template <class T>
void Treaps<T>::left_rotation(nptr x)
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
}

template <class T>
void Treaps<T>::right_rotation(nptr x)
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
}

template <class T>
NODE<T>* Treaps<T>::min_subtree(nptr x)
{
	if (x != sentinel)
	{
		while (x->left != sentinel)
			x = x->left;
	}
	return x;
}

template <class T>
T Treaps<T>::min()
{
	nptr x = min_subtree(root);
	if (root != sentinel)
		return x->key;
	else
		throw new exception("root is sentinel");
}

template <class T>
NODE<T>* Treaps<T>::max_subtree(nptr x)
{
	if (x != sentinel)
	{
		while (x->right != sentinel)
			x = x->right;
	}
	return x;
}

template <class T>
T Treaps<T>::max()
{
	nptr x = max_subtree(root);
	if (root != sentinel)
		return x->key;
	else
		throw new exception("root is sentinel");
}

template <class T>
NODE<T>* Treaps<T>::successor(nptr x)
{
	if (x->right != sentinel)
		return min_subtree(x->right);

	while (x != root && x->parent->right == x)
		x = x->parent;

	return x->parent;
}

template <class T>
NODE<T>* Treaps<T>::predecessor(nptr x)
{
	if (x->left != sentinel)
		return max_subtree(x->left);

	while (x != root && x->parent->left == x)
		x = x->parent;

	return x->parent;
}

template <class T>
void Treaps<T>::print_tree(nptr x)
{
	if (x == sentinel)
		return;

	print_tree(x->left);
	cout << x->key << ' ';
	print_tree(x->right);

	return;
}

template <class T>
void Treaps<T>::print()
{
	print_tree(root);
	cout << endl;
}

template <class T>
void Treaps<T>::nonrecursive_print()
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
void Treaps<T>::cleaner(nptr x)
{
	if (x == sentinel)
		return;
	cleaner(x->left);
	cleaner(x->right);
	delete x;
}

template <class T>
Treaps<T>::~Treaps()
{
	cleaner(root);
	delete sentinel;
}

#endif