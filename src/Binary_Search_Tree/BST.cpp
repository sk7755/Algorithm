#ifndef __BST_CPP__
#define __BST_CPP__

#include "BST.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <class T>
BST<T>::BST() : n(0), root(nullptr) {}

template <class T>
BST<T>::BST(T a[], int n)
{
	knuth_shuffle(a, n);
	for (int i = 0; i < n; i++)
		insertion(a[i]);
}

template <class T>
void BST<T>::knuth_shuffle(T a[], int n)
{
	init_seed();
	for (int i = 0; i < n; i++)
	{
		std::swap(a[i], a[uniform(i, n - 1)]);
	}
}

template <class T>
void BST<T>::init_seed()
{
	srand(time(NULL));
}

template <class T>
int BST<T>::uniform(int a, int b)
{
	int value = rand() | (rand() << 15);
	return value % (b - a + 1) + a;
}

template <class T>
int BST<T>::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}

template <class T>
int BST<T>::size()
{
	return n;
}

template <class T>
void BST<T>::insertion(T key)
{
	nptr pnew = new NODE<T>;
	pnew->key = key;
	pnew->left = pnew->right = nullptr;
	
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
	if (!y)
	{
		root = pnew;
		return;
	}
	
	if (y->key < key)
		y->right = pnew;
	else
		y->left = pnew;
	n++;
}

template <class T>
NODE<T>* BST<T>::search(T key)
{
	nptr x = root;

	while (x)
	{
		if (x->key < key)
			x = x->right;
		else if (x->key > key)
			x = x->left;
		else
			return x;
	}

	return nullptr;
}

template <class T>
void BST<T>::transparent(nptr u, nptr v)
{
	if (u == root)
		root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;

	if (v != nullptr)
		v->parent = u->parent;
}


template <class T>
NODE<T>* BST<T>::min_subtree(nptr x)
{
	while (x->left)
		x = x->left;

	return x;
}

template <class T>
T BST<T>::min()
{
	nptr x = min_subtree(root);
	if (x)
		return x->key;
}

template <class T>
NODE<T>* BST<T>::max_subtree(nptr x)
{
	while (x->right)
		x = x->right;

	return x;
}

template <class T>
T BST<T>::max()
{
	nptr x = max_subtree(root);
	if (x)
		return x->key;
}

template <class T>
NODE<T>* BST<T>::successor(nptr x)
{
	if (x->right)
		return min_subtree(x->right);

	while (x != root && x->parent->right == x)
		x = x->parent;

	return x->parent;
}

template <class T>
NODE<T>* BST<T>::predecessor(nptr x)
{
	if (x->left)
		return max_subtree(x->left);

	while (x != root && x->parent->left == x)
		x = x->parent;

	return x->parent;
}

template <class T>
void BST<T>::deletion(nptr x)
{
	if (x == nullptr)
		return;

	if (x->left == nullptr)
		transparent(x, x->right);
	else if (x->right == nullptr)
		transparent(x, x->left);
	else
	{
		nptr y = min_subtree(x->right);
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
}

template <class T>
void BST<T>::nonrecursive_print()	//nonrecursive
{
	nptr x = root;
	int pre = 0; //0 = parent, 1 = left child, 2 = right child 

	if(x == nullptr)
		return;

	while (1)
	{
		if (pre == 0)
		{
			if (x->left)
				x = x->left;
			else
				pre = 1;
		}
		if (pre == 1)
		{
			cout << x->key << ' ';
			if (x->right)
			{
				pre = 0;
				x = x->right;
			}
			else
				pre = 2;
		}
		if (pre == 2)
		{
			if (x->parent == nullptr)
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
void BST<T>::print_tree(nptr x)
{
	if (x == nullptr)
		return;

	print_tree(x->left);
	cout << x->key << ' ';
	print_tree(x->right);

	return;
}

template <class T>
void BST<T>::print()
{
	print_tree(root);
	cout << endl;
}

template <class T>
void BST<T>::cleaner(nptr x)
{
	if (x == nullptr)
		return;
	cleaner(x->left);
	cleaner(x->right);
	delete x;
}

template <class T>
BST<T>::~BST()
{
	cleaner(root);
}

#endif