#include "Rooted_Tree.h"

Rooted_Tree::Rooted_Tree() : root(nullptr){}

void Rooted_Tree::push(int key)
{

	nptr pnew = new NODE;
	pnew->right = pnew->left = nullptr;
	pnew->key = key;

	if (!root)
	{
		root = pnew;
		return;
	}

	nptr p = root;
	nptr pre = nullptr;
	nptr parent = nullptr;
	while (p)
	{
		if (p->key < key)
		{
			pre = p;
			p = p->right;
		}
		else
		{
			pre = nullptr;
			parent = p;
			p = p->left;
		}
	}

	if (pre)
		pre->right = pnew;
	else
		parent->left = pnew;

}

nptr Rooted_Tree::search(int key)
{
	nptr p = root;

	while (p)
	{
		if (p->key < key)
			p = p->right;
		else if (p->key == key)
			return p;
		else
			p = p->left;
	}

	return nullptr;
}
void Rooted_Tree::print_all()
{
	print(root);
	printf("\n");
}

void Rooted_Tree::print(nptr x)
{
	for (nptr p = x; p; p = p->right)
	{
		print(p->left);
		printf("%d ",p->key);
	}
}

void Rooted_Tree::delete_line(nptr x)
{
	for (nptr p = x; p;)
	{
		delete_line(p->left);
		nptr next = p->right;
		delete p;
		p = next;
	}
}
Rooted_Tree::~Rooted_Tree()
{
	delete_line(root);
}