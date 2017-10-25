#include "BST.h"
#include <cstdio>

BST::BST() : n(0), root(nullptr) {}
int BST::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}
int BST::size()
{
	return n;
}
void BST::insertion(int key)
{
	nptr pnew = new NODE;
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
}
nptr BST::search(int key)
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

void BST::transparent(nptr u, nptr v)
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
nptr BST::min(nptr x)
{
	while (x->left)
		x = x->left;

	return x;
}
nptr BST::max(nptr x)
{
	while (x->right)
		x = x->right;

	return x;
}

nptr BST::successor(nptr x)
{
	if (x->right)
		return min(x->right);

	while (x != root && x->parent->right == x)
		x = x->parent;

	return x->parent;
}

nptr BST::predecessor(nptr x)
{
	if (x->left)
		return max(x->left);

	while (x != root && x->parent->left == x)
		x = x->parent;

	return x->parent;
}

void BST::deletion(nptr x)
{
	if (x == nullptr)
		return;

	if (x->left == nullptr)
		transparent(x, x->right);
	else if (x->right == nullptr)
		transparent(x, x->left);
	else
	{
		nptr y = min(x->right);
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
}

void BST::nonrecursive_print()	//nonrecursive
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
			printf("%d ", x->key);
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
	printf("\n");
}

void BST::print_tree(nptr x)
{
	if (x == nullptr)
		return;

	print_tree(x->left);
	printf("%d ", x->key);
	print_tree(x->right);

	return;
}

void BST::print()
{
	print_tree(root);
	printf("\n");
}

void BST::cleaner(nptr x)
{
	if (x == nullptr)
		return;
	cleaner(x->left);
	cleaner(x->right);
	delete x;
}

BST::~BST()
{
	cleaner(root);
}