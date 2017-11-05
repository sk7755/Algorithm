#ifndef __RBtree_CPP__
#define __RBtree_CPP__

#include "RBtree.h"
#include <iostream>

using namespace std;
using namespace RBTREE;

template <class T>
RBtree<T>::RBtree() :n(0)
{
	sentinel = new NODE<T>;
	sentinel->color = BLACK;
	root = sentinel;
}

template <class T>
void RBtree<T>::insertion(T key)
{
	nptr pnew = new NODE<T>;
	pnew->key = key;
	pnew->left = pnew->right = sentinel;
	pnew->color = RED;
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
void RBtree<T>::insert_fixup(nptr x)
{
	while (x->parent->color == RED)
	{
		if (x->parent == x->parent->parent->left)
		{
			nptr y = x->parent->parent->right;	//uncle of x
			if (y->color == RED)
			{
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else
			{
				if (x->parent->right == x)
				{
					x = x->parent;
					left_rotation(x);
				}
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				right_rotation(x->parent->parent);
			}
		}
		else
		{
			nptr y = x->parent->parent->left;	//uncle of x
			if (y->color == RED)
			{
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else
			{
				if (x->parent->left == x)
				{
					x = x->parent;
					right_rotation(x);
				}
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				left_rotation(x->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

template <class T>
void RBtree<T>::deletion(nptr x)
{
	if (x == sentinel)
		return;

	COLOR y_orig_color = x->color;
	nptr z;	// z is child of y

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
		y_orig_color = y->color;
		z = y->right;
		if (y->parent == x)
			z->parent = y;
		else
		{
			transparent(y, y->right);
			y->right = x->right;
			x->right->parent = y;
		}
		transparent(x, y);
		y->left = x->left;
		y->left->parent = y;
		y->color = x->color;
	}

	if (y_orig_color == BLACK)
		delete_fixup(z);

	delete x;
	n--;
}

template <class T>
void RBtree<T>::delete_fixup(nptr x)
{
	nptr w; //w is sibiling
	while (x != root && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			w = x->parent->right;
			
			if (w->color == RED)
			{
				x->parent->color = RED;
				w->color = BLACK;
				left_rotation(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					right_rotation(w);
					w = w->parent;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				left_rotation(x->parent);
				x = root;
			}
		}
		else
		{
			w = x->parent->left;

			if (w->color == RED)
			{
				x->parent->color = RED;
				w->color = BLACK;
				right_rotation(x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					left_rotation(w);
					w = w->parent;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				right_rotation(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

template <class T>
NODE<T>* RBtree<T>::search(T key)
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
int RBtree<T>::black_height(nptr x)	//internal node
{
	int black_height = 0;

	while (x != sentinel)
	{
		if (x->color = BLACK)
			black_height++;
	}

	return black_height;
}

template <class T>
int RBtree<T>::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}

template <class T>
int RBtree<T>::size()
{
	return n;
}

template <class T>
void RBtree<T>::transparent(nptr u, nptr v)
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
void RBtree<T>::left_rotation(nptr x)
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
void RBtree<T>::right_rotation(nptr x)
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
NODE<T>* RBtree<T>::min_subtree(nptr x)
{
	if (x != sentinel)
	{
		while (x->left != sentinel)
			x = x->left;
	}
	return x;
}

template <class T>
T RBtree<T>::min()
{
	nptr x = min_subtree(root);
	if (root != sentinel)
		return x->key;
	else
		throw new exception("root is sentinel");
}

template <class T>
NODE<T>* RBtree<T>::max_subtree(nptr x)
{
	if (x != sentinel)
	{
		while (x->right != sentinel)
			x = x->right;
	}
	return x;
}

template <class T>
T RBtree<T>::max()
{
	nptr x = max_subtree(root);
	if (root != sentinel)
		return x->key;
	else
		throw new exception("root is sentinel");
}

template <class T>
NODE<T>* RBtree<T>::successor(nptr x)
{
	if (x->right != sentinel)
		return min_subtree(x->right);

	while (x != root && x->parent->right == x)
		x = x->parent;

	return x->parent;
}

template <class T>
NODE<T>* RBtree<T>::predecessor(nptr x)
{
	if (x->left != sentinel)
		return max_subtree(x->left);

	while (x != root && x->parent->left == x)
		x = x->parent;

	return x->parent;
}

template <class T>
void RBtree<T>::print_tree(nptr x)
{
	if (x == sentinel)
		return;

	print_tree(x->left);
	cout << x->key << ' ';
	print_tree(x->right);

	return;
}

template <class T>
void RBtree<T>::print()
{
	print_tree(root);
	cout << endl;
}

template <class T>
void RBtree<T>::nonrecursive_print()
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
void RBtree<T>::cleaner(nptr x)
{
	if (x == sentinel)
		return;
	cleaner(x->left);
	cleaner(x->right);
	delete x;
}

template <class T>
RBtree<T>::~RBtree()
{
	cleaner(root);
	delete sentinel;
}

#endif