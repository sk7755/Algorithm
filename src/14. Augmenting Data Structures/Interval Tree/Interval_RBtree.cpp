#include "Interval_RBtree.h"
#include <iostream>

using namespace std;
using namespace INTERVAL_RBTREE;

ostream& INTERVAL_RBTREE::operator<<(ostream& os, const interval i)
{
	os << "[ " << i.s << " , " << i.f << " ]";
	return os;
}


istream& INTERVAL_RBTREE::operator>>(istream& is, interval& i)
{
	is >> i.s >> i.f;
	
	if (i.s > i.f)
	{
		int tmp = i.s;
		i.s = i.f;
		i.f = tmp;
	}
	
	return is;
}

Interval_RBtree::Interval_RBtree() :n(0)
{
	sentinel = new NODE;
	sentinel->color = BLACK;
	root = sentinel;
}

void Interval_RBtree::insertion(interval i)
{
	nptr pnew = new NODE;
	pnew->i = i;
	pnew->left = pnew->right = sentinel;
	pnew->color = RED;
	pnew->max = i.f;
	nptr x = root;
	nptr y = sentinel;
	while (x != sentinel)
	{
		y = x;
		x->max = MAX(x, pnew)->max;
		if (x->i.s < i.s)
			x = x->right;
		else
			x = x->left;
	}
	pnew->parent = y;
	if (y == sentinel)
		root = pnew;
	else if (y->i.s < i.s)
		y->right = pnew;
	else
		y->left = pnew;
	n++;

	insert_fixup(pnew);
}

void Interval_RBtree::insert_fixup(nptr x)
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

void Interval_RBtree::deletion(nptr x)
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

		nptr y = x->right;
		while (y->left != sentinel)
			y = y->left;
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
		y->left = x->left;
		y->left->parent = y;
		y->max = MAX(MAX(y->left,y->right),y)->max;
		y->color = x->color;
		transparent(x, y);
	}

	if (y_orig_color == BLACK)
		delete_fixup(z);

	delete x;
	n--;
}

void Interval_RBtree::delete_fixup(nptr x)
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

int Interval_RBtree::isOverlap(interval a, interval b)
{
	if (a.f < b.s)
		return 0;
	if (a.s > b.f)
		return 0;

	return 1;
}

NODE* Interval_RBtree::search(interval i)
{
	nptr x = root;

	while (x != sentinel && !isOverlap(x->i,i))
	{
		if (x->left != sentinel && x->left->max >= i.s)
			x = x->left;
		else
			x = x->right;
	}

	return x;
}

int Interval_RBtree::isempty()
{
	if (n == 0)
		return 1;
	else
		return 0;
}

int Interval_RBtree::size()
{
	return n;
}

void Interval_RBtree::transparent(nptr u, nptr v)
{
	if (u == root)
		root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;

	v->parent = u->parent;


	v = v->parent;
	while (v != sentinel)
	{
		v->max = MAX(MAX(v->left,v->right),v)->max;
		v = v->parent;
	}

}

void Interval_RBtree::left_rotation(nptr x)
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

	x->max = MAX(MAX(x->left,x->right),x)->max;
	y->max = MAX(MAX(y->left,y->right),y)->max;
}

void Interval_RBtree::right_rotation(nptr x)
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

	x->max = MAX(MAX(x->left, x->right),x)->max;
	y->max = MAX(MAX(y->left, y->right),y)->max;
}

void Interval_RBtree::print_tree(nptr x)
{
	if (x == sentinel)
		return;

	print_tree(x->left);
	cout << x->i << ' ';
	print_tree(x->right);

	return;
}

void Interval_RBtree::print()
{
	print_tree(root);
	cout << endl;
}

void Interval_RBtree::nonrecursive_print()
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
			cout << x->i << ' ';
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

void Interval_RBtree::cleaner(nptr x)
{
	if (x == sentinel)
		return;
	cleaner(x->left);
	cleaner(x->right);
	delete x;
}

Interval_RBtree::~Interval_RBtree()
{
	cleaner(root);
	delete sentinel;
}
